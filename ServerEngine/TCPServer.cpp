#include "TCPServer.h"
#include <uv.h>

static uv_tcp_t server_;
TCPServer::TCPServer(/* args */)
    :TCPEvent_(nullptr)
{
}

TCPServer::~TCPServer()
{
}

static void onNewConnection(uv_stream_t *server, int status)
{
     if (status < 0) 
     {
        fprintf(stderr, "New connection error %s\n", uv_strerror(status));
        // error!
        return;
    }

    auto conn = ConnectionMgr::getInstace()->create();
    if(conn == nullptr)
    {
         fprintf(stderr, "New connection error %s\n", "max conn");
        // error!
        return;
    }
    
    conn->accept(server);
}

bool TCPServer::listen(int port, int backlog)
{
    uv_tcp_init(uv_default_loop(), &server_);
    server_.data = this;

    struct sockaddr_in addr;
    uv_ip4_addr("0.0.0.0", port, &addr);

    uv_tcp_bind(&server_, (const struct sockaddr *)&addr, 0);
    int r = uv_listen((uv_stream_t *)&server_, backlog, onNewConnection);
    if (r)
    {
        fprintf(stderr, "Listen error %s\n", uv_strerror(r));
        return false;
    }

    return true;
}
void TCPServer::close()
{
    uv_close((uv_handle_t *)&server_, nullptr); 
}
void TCPServer::setEventHandle(ITCPEvent* handle)
{
    TCPEvent_ = handle;
}