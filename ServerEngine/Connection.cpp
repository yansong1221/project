#include "Connection.h"

#include <uv.h>

enum ConnStatus
{
	CONNSTATUS_DEATH,						//死亡连接
	CONNSTATUS_DANGER,						//需要发送心跳的连接
	CONNSTATUS_SAFE							//安全连接
};

#define MAX_PACKET_SIZE						1024

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
		free(handle);
	});

	TCPEvent_->onCloseConnect(getSocketID());

	active_ = false;
	readBuf_.clear();
	client_ = nullptr;

	do
	{
		roundIndex_++;
	} while (roundIndex_ == 0);

	connStatus_ = CONNSTATUS_DEATH;
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
	connStatus_ = CONNSTATUS_SAFE;
	active_ = true;
	client_ = client;
	((uv_tcp_t*)client_)->data = this;

	TCPEvent_->onNewConnect(getSocketID());
	recvData();
}

void Connection::check()
{
	if (active() == false) return;
	switch (connStatus_)
	{
	case CONNSTATUS_SAFE:	
		connStatus_ = CONNSTATUS_DANGER;
		break;
	case CONNSTATUS_DANGER:
		connStatus_ = CONNSTATUS_DEATH;
		send(ENGINE_PING_MSGID, nullptr, 0);
		break;
	case CONNSTATUS_DEATH:
		close();
		break;
	default:
		break;
	}
}

void Connection::parseDsata()
{
	connStatus_ = CONNSTATUS_SAFE;

	while (readBuf_.size() >= sizeof(TCPHeader))
	{
		TCPHeader* header = (TCPHeader*)readBuf_.data();
		auto len = ::ntohl(header->len);
		auto msgID = ::ntohl(header->msgID);

		if (len >= MAX_PACKET_SIZE)
		{
			close();
			break;
		}

		if(len >= readBuf_.size() + sizeof(TCPHeader)) break;

		if (msgID != ENGINE_PING_MSGID)
		{
			TCPEvent_->onNewMessage(getSocketID(), msgID, (char*)readBuf_.data() + sizeof(TCPHeader), len);
		}

		readBuf_.removeFront(sizeof(TCPHeader) + len);
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
			conn->readBuf_.appendBinary(buf->base, nread);
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

void Connection::send(uint32_t msgID,const void *data, size_t sz)
{
	if (active() == false)
	{
		return;
	}

	TCPHeader Header = {0};
	Header.msgID = ::htonl(msgID);
	Header.len = ::htonl(sz);

	write_req_t *req = (write_req_t *)malloc(sizeof(write_req_t));

	char *buf = (char *)malloc(sz + sizeof(TCPHeader));
	memcpy(buf, &Header, sizeof(TCPHeader));
	if(sz != 0) memcpy(buf + sizeof(TCPHeader), data, sz);

	req->buf = uv_buf_init(buf, sizeof(TCPHeader) + sz);

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