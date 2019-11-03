#include "EventDispatcher.h"

#include <iostream>
int main()
{
    EventDispatcher Dispatcher;
    Dispatcher.run();

    std::cout << "hello world" << std::endl;
    return 0;
}