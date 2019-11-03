

#include "ServerEngine/EventDispatcher.h"
#include "ServerEngine/TCPServer.h"

#include <iostream>
class App:public ITCPEvent {
public:
	virtual void onNewConnect(uint32_t socketID)
	{

	}
	virtual void onNewMessage(uint32_t socketID, const void *p, size_t n)
	{

	}
	virtual void onCloseConnect(uint32_t socketID)
	{

	}
};
int main()
{
	EventDispatcher app;
	TCPServer  server;
	App aaa;
	server.listen(8800, 1024);
	server.setEventHandle(&aaa);

	app.addTimer(1000, [](TimerWapper timer)
	{
		static int i = 0;
		i++;
		if (i == 10)
		{
			timer.cancel();
		}
		std::cout << "----" << std::endl;
	});

	return app.run();
}