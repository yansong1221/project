#include "Connection.h"

typedef struct
{
    uv_write_t req;
    uv_buf_t buf;
} write_req_t;

Connection::Connection(uint16_t bindIndex)
    : bindIndex_(bindIndex),
      active_(false)
{
    roundIndex_ = 1;
}

Connection::~Connection()
{
}
uint32_t Connection::getSocketID() const
{
    return ((uint32_t)bindIndex_ << 16) | roundIndex_;
}
void Connection::detach()
{
    do
    {
        roundIndex_++;
    } while (roundIndex_ == 0);
}

void Connection::accept(uv_stream_t *server)
{
    if (active())
    {
        return;
    }

    uv_tcp_init(uv_default_loop(), &client_);
    client_.data = this;

    if (uv_accept(server, (uv_stream_t *)&client_) == 0)
    {
        //recv data
        uv_read_start((uv_stream_t *)&client_,

                      //分配内存
                      [](uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf) {
                          buf->base = (char *)malloc(suggested_size);
                          buf->len = suggested_size;
                      },

                      //接收数据回调
                      [](uv_stream_t *client, ssize_t nread, const uv_buf_t *buf) {
                          auto conn = (Connection *)client->data;
                          if (nread > 0)
                          {

                              conn->onEventRead(buf->base, nread);
                              return;
                          }
                          if (nread < 0)
                          {
                              if (nread != UV_EOF)
                                  fprintf(stderr, "Read error %s\n", uv_err_name(nread));

                              conn->onEventClose();
                          }

                          free(buf->base);
                      });

        active_ = true;
    }
    else
    {
        uv_close((uv_handle_t *)&client_, nullptr);
    }
}
bool Connection::active() const
{
    return active_;
}
void Connection::close()
{
    if (active() == false)
    {
        return;
    }
    uv_close((uv_handle_t *)&client_, nullptr);
}
void Connection::send(const char *p, size_t n)
{
    if (active() == false)
    {
        return;
    }

    write_req_t *req = (write_req_t *)malloc(sizeof(write_req_t));

    char *buf = (char *)malloc(n);
    memcpy(buf, p, n);

    req->buf = uv_buf_init(buf, n);
    uv_write((uv_write_t *)req, (uv_stream_t *)&client_, &req->buf, 1,
             //发送完成回调
             [](uv_write_t *req, int status) {
                 if (status)
                 {
                     fprintf(stderr, "Write error %s\n", uv_strerror(status));
                 }
                 write_req_t *wr = (write_req_t *)req;
                 free(wr->buf.base);
                 free(wr);
             });
}
void Connection::onEventRead(const char *p, size_t n)
{
    std::copy(p, p + n, std::back_inserter(readBuf_));
}
void Connection::onEventClose()
{
    
    uv_close((uv_handle_t *)&client_, nullptr);
    active_ = false;
}
ConnectionMgr::ConnectionMgr()
{
}
ConnectionMgr::~ConnectionMgr()
{
}
Connection *ConnectionMgr::create()
{
}
ConnectionMgr *ConnectionMgr::getInstace()
{
    if (instance_ == nullptr)
    {
        instance_ = new ConnectionMgr;
        return instance_;
    }

    return instance_;
}