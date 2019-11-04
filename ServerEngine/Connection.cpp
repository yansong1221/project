#include "Connection.h"

#include <uv.h>

typedef struct
{
	uv_write_t req;
	uv_buf_t buf;
} write_req_t;

Connection::Connection(uint16_t bindIndex, ITCPEvent* handle)
	: bindIndex_(bindIndex),
	active_(false),
	client_(nullptr),
	TCPEvent_(handle)
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
	uv_close((uv_handle_t *)client_, [](uv_handle_t* handle) 
	{
		auto conn = ((Connection*)handle->data);

		conn->TCPEvent_->onCloseConnect(conn->getSocketID());

		conn->active_ = false;
		conn->readBuf_.clear();
		conn->client_ = nullptr;

		do
		{
			conn->roundIndex_++;
		} while (conn->roundIndex_ == 0);

		free(handle);
	});
}


uint16_t Connection::getRoundIndex() const
{
	return roundIndex_;
}

void Connection::attach(void* client)
{
	if (active())
	{
		return;
	}

	active_ = true;
	client_ = client;
	((uv_tcp_t*)client_)->data = this;

	TCPEvent_->onNewConnect(getSocketID());
	recvData();
}

void Connection::parseDsata()
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

		if(len >= readBuf_.size() + sizeof(uint32_t)) break;

		const char* data = &readBuf_[sizeof(uint32_t)];
		TCPEvent_->onNewMessage(getSocketID(), data, len);

		readBuf_.erase(readBuf_.begin(), readBuf_.begin() + sizeof(uint32_t) + len);
	}
}

void Connection::recvData()
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
		auto conn = (Connection *)client->data;
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

void Connection::send(const void *p, size_t n)
{
	if (active() == false)
	{
		return;
	}

	uint32_t len = ::htonl(n);


	write_req_t *req = (write_req_t *)malloc(sizeof(write_req_t));

	char *buf = (char *)malloc(n + sizeof(uint32_t));
	memcpy(buf, &len, sizeof(uint32_t));
	memcpy(buf + sizeof(uint32_t), p, n);

	req->buf = uv_buf_init(buf, n);
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