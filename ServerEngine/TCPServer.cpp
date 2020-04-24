#include "TCPServer.h"
#include <uv.h>

#include <algorithm>

TCPServer::TCPServer(ITCPEvent* handle)
    :TCPEvent_(handle),
	server_(nullptr)
{
}

TCPServer::~TCPServer()
{
}

bool TCPServer::listen(int port, int backlog)
{
	if (server_ != nullptr) return false;

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

		uv_tcp_t* client = (uv_tcp_t*)malloc(sizeof(uv_tcp_t));
		uv_tcp_init(uv_default_loop(), client);

		if (uv_accept((uv_stream_t*)server, (uv_stream_t *)client) == 0)
		{
			conn->attach(client);	
		}
		else
		{
			uv_close((uv_handle_t *)client, [](uv_handle_t* handle)
			{
				free(handle);
			});
		}
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
	if (server_ == nullptr) return;

	for (const auto& v : conns_)
	{
		v->close();
	}

	uv_close((uv_handle_t *)server_, [](uv_handle_t* handle)
	{
		free(handle);
	});
	server_ = nullptr;
}

void TCPServer::sendData(uint64_t socketID, uint32_t msgID, const void* data, size_t sz)
{
	if (server_ == nullptr) return;

	uint16_t bindIndex = socketID & 0xffff0000;
	uint16_t roundIndex = (socketID & 0x0000ffff) >> 16;

	if (bindIndex > conns_.size()) return;
	if (bindIndex == 0) return;

	auto conn = conns_.at(bindIndex - 1);
	if (conn->getRoundIndex() != roundIndex) return;

	conn->send(msgID, data, sz);
}


void TCPServer::closeSocket(uint64_t socketID)
{
	if (server_ == nullptr) return;

	uint16_t bindIndex = socketID & 0xffff0000;
	uint16_t roundIndex = (socketID & 0x0000ffff) >> 16;

	if (bindIndex > conns_.size()) return;
	if (bindIndex == 0) return;

	auto conn = conns_.at(bindIndex - 1);
	if (conn->getRoundIndex() != roundIndex) return;

	conn->close();
}

void TCPServer::checkConnection()
{
	for (auto conn : conns_)
	{
		if(conn->active() == false) continue;
		conn->check();
	}
}

Connection * TCPServer::createConnection()
{
	auto iter = std::find_if(conns_.begin(), conns_.end(), [](Connection* conn)
	{
		return conn->active() == false;
	});
	if (iter != conns_.end()) return *iter;

	auto conn = new Connection(conns_.size() + 1, TCPEvent_);
	conns_.push_back(conn);
	return conn;
}
