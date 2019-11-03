#include <uv.h>
#include <vector>

class ITCPEvent
{
public:
    virtual void onNewConnect(uint32_t socketID) = 0;
    virtual void onNewMessage(uint32_t socketID, void *p, size_t n) = 0;
    virtual void onCloseConnect(uint32_t socketID) = 0;
};

class Connection
{
private:
    /* data */
public:
    Connection(uint16_t bindIndex);
    ~Connection();

public:
    uint32_t getSocketID() const;
    void detach();

    bool active() const;

    void accept(uv_stream_t *server);

    void send(const char* p,size_t n);

    void close();
private:
    void onEventRead(const char* p,size_t n);
    void onEventClose();
private:
    uv_tcp_t client_;

private:
    uint16_t roundIndex_;
    uint16_t bindIndex_;

    bool active_;

    std::vector<char> readBuf_;
};

class ConnectionMgr
{
public:
    ConnectionMgr();
    ~ConnectionMgr();

    ConnectionMgr(ConnectionMgr &) = delete;
    ConnectionMgr &operator=(ConnectionMgr &) = delete;

public:
    Connection *create();
    static ConnectionMgr *getInstace();

private:
    std::vector<Connection *> conns_;
    static ConnectionMgr *instance_;
};
