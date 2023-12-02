#include "muduo/net/EventLoop.h"
#include "muduo/base/Logging.h"
muduo::net::EventLoop loop;

int main()
{
    LOG_TRACE << "TRACE...";
    LOG_INFO << "INFO...";
    loop.loop();
}