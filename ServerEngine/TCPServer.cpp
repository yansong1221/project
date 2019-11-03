#include "TCPServer.h"
#include <uv.h>

#include <algorithm>

TCPServer::TCPServer(/* args */)
    :TCPEvent_(nullptr)
{
}

TCPServer::~TCPServer()
{
}

bool TCPServer::listen(int port, int backlog)
{
	server_ = malloc(sizeof(uv_tcp_t));
    uv_tcp_init(uv_default_loop(), (uv_tcp_t*)server_);
	((uv_tcp_t*)server_)->data = this;

    struct sockaddr_in addr;
    uv_ip4_addr("0.0.0.0", port, &addr);

    uv_tcp_bind((uv_tcp_t*)server_, (const struct sockaddr *)&addr, 0);

	int r = uv_listen((uv_stream_t *)server_, backlog, [](uv_stream_t *server, int status)
	{
		if (status < 0)
		{
			fprintf(stderr, "New connection error %s\n", uv_strerror(status));
			// error!
			return;
		}

		auto conn = ((TCPServer*)server->data)->createConnection();
		if (conn == nullptr)
		{
			fprintf(stderr, "New connection error %s\n", "max conn");
			// error!
			return;
		}

		conn->accept(server);
	});

    if (r)
    {
        fprintf(stderr, "Listen error %s\n", uv_strerror(r));
        return false;
    }

    return true;
}
void TCPServer::close()
{
	uv_close((uv_handle_t *)server_, [](uv_handle_t* handle)
	{
		auto srv = (TCPServer*)handle->data;
		srv->server_ = nullptr;
		free(handle);
	});
}
void TCPServer::setEventHandle(ITCPEvent* handle)
{
    TCPEvent_ = handle;
}


void TCPServer::sendData(uint32_t socketID, const void* p, size_t n)
{
	uint16_t bindIndex = socketID & 0xffff0000;
	uint16_t roundIndex = (socketID & 0x0000ffff) >> 16;

	if (bindIndex > conns_.size()) return;

	auto conn = conns_.at(bindIndex);
	if (conn->getRoundIndex() != roundIndex) return;

	conn->send(p, n);
}


void TCPServer::closeSocket(uint32_t socketID)
{
	uint16_t bindIndex = socketID & 0xffff0000;
	uint16_t roundIndex = (socketID & 0x0000ffff) >> 16;

	if (bindIndex > conns_.size()) return;

	auto conn = conns_.at(bindIndex);
	if (conn->getRoundIndex() != roundIndex) return;

	conn->close();
}

Connection * TCPServer::createConnection()
{
	auto iter = std::find_if(conns_.begin(), conns_.end(), [](Connection* conn)
	{
		return conn->active() == false;
	});
	if (iter != conns_.end()) return *iter;

	auto conn = new Connection(conns_.size(), TCPEvent_);
	conns_.push_back(conn);
	return conn;
}
