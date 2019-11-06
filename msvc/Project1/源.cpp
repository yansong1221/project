

#include "ServerEngine/ServerEngine.h"

#include <iostream>
#include <signal.h>
#include <thread>
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
class taskTest : public IThreadTask
{
public:
	~taskTest()
	{
		LOG(INFO) << "Ïß³ÌÎö¹¹";
	}
public:
	virtual void run()
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
};
int main()
{
	EventDispatcher app;
	TCPServer  server;
	App aaa;
	server.listen(8800, 1024);
	server.setEventHandle(&aaa);

	for (int i = 0; i < 10000; ++i)
	{
		app.addTimer(1000, [&](TimerWapper timer)
		{
			if (timer.runCount() == 10)
			{
				timer.cancel();
				
			}
			std::cout << "----" << std::endl;		
		});	
	}
	
	app.addSignal(SIGINT, [&]()
	{
		app.close();
	});

	for (int i = 0; i < 10000; ++i)
	{
		app.addTask(new taskTest);
	}

	return app.run();
}