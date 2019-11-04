#include "TCPClient.h"
#include <uv.h>

#include "Connection.h"
#include <algorithm>

typedef struct
{
	uv_write_t req;
	uv_buf_t buf;
} write_req_t;

TCPClient::TCPClient()
{
	client_ = malloc(sizeof(uv_tcp_t));
	((uv_tcp_t*)client_)->data = this;
}

TCPClient::~TCPClient()
{
	free(client_);
}

void TCPClient::connect(const std::string& host, int port)
{
	uv_tcp_init(uv_default_loop(), (uv_tcp_t*)client_);

	uv_connect_t * req = (uv_connect_t*)malloc(sizeof(uv_connect_t));
	req->data = this;

	struct sockaddr_in addr;
	uv_ip4_addr(host.c_str(), port, &addr);

	uv_tcp_connect((uv_connect_t*)req, (uv_tcp_t*)client_, (sockaddr*)&addr,
		[](uv_connect_t* req, int status)
	{
		auto client = (TCPClient*)req->data;

		if (status < 0)
		{
			fprintf(stderr, "Connection error %s\n", uv_strerror(status));
			client->connectHandle_(false);
		}
		else
		{
			client->connectHandle_(true);
		}

		free(req);
	});

}

void TCPClient::setConnectHandle(ClientConnectHandle handle)
{
	connectHandle_ = handle;
}

void TCPClient::setReadHandle(ClientReadHandle handle)
{
	readHandle_ = handle;
}

void TCPClient::setCloseHandle(ClientCloseHandle handle)
{
	closeHandle_ = handle;
}

void TCPClient::sendData(const void* data, size_t sz)
{
	uint32_t len = ::htonl(sz);

	write_req_t *req = (write_req_t *)malloc(sizeof(write_req_t));

	char *buf = (char *)malloc(sz + sizeof(uint32_t));
	memcpy(buf, &len, sizeof(uint32_t));
	memcpy(buf + sizeof(uint32_t), data, sz);

	req->buf = uv_buf_init(buf, sz + sizeof(uint32_t));
	uv_write((uv_write_t *)req, (uv_stream_t *)client_, &req->buf, 1,
		//callback

	[](uv_write_t *req, int status) {
		if (status != 0)
		{
			fprintf(stderr, "Write error %s\n", uv_strerror(status));
		}
		write_req_t *wr = (write_req_t *)req;
		free(wr->buf.base);
		free(wr);
	});
}
void TCPClient::parseDsata()
{
	while (readBuf_.size() >= sizeof(uint32_t))
	{
		uint32_t len = *(uint32_t*)readBuf_.data();
		len = ::ntohl(len);

		if (len >= 1024)
		{
			close();
			break;
		}

		if (len >= readBuf_.size() + sizeof(uint32_t)) break;

		const char* data = &readBuf_[sizeof(uint32_t)];
		readHandle_(data, len);

		readBuf_.erase(readBuf_.begin(), readBuf_.begin() + sizeof(uint32_t) + len);
	}
}
void TCPClient::recvData()
{
	//recv data
	uv_read_start((uv_stream_t *)client_,

		//alloc memory
		[](uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf)
	{
		buf->base = (char *)malloc(suggested_size);
		buf->len = suggested_size;
	},

		//callback
		[](uv_stream_t *client, ssize_t nread, const uv_buf_t *buf) {
		auto conn = (TCPClient *)client->data;
		if (nread > 0)
		{
			std::copy(buf->base, buf->base + nread, std::back_inserter(conn->readBuf_));
			//parse data
			conn->parseDsata();
			return;
		}
		if (nread < 0)
		{
			if (nread != UV_EOF)
				fprintf(stderr, "Read error %s\n", uv_err_name(nread));
			conn->close();
		}

		free(buf->base);
	});
}
void TCPClient::close()
{
	uv_close((uv_handle_t *)client_, [](uv_handle_t* handle)
	{
		((TCPClient*)handle->data)->closeHandle_();
	});
}
