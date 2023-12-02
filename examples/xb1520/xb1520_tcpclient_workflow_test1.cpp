#include "muduo/net/TcpClient.h"
#include "muduo/net/EventLoop.h"
#include "muduo/base/Logging.h"

using namespace muduo;
using namespace net;

int main()
{
    EventLoop loop;
    TcpClient cli(&loop,InetAddress(9527),"Test");
    cli.connect();
    cli.setConnectionCallback([](const TcpConnectionPtr& conn){
        LOG_INFO << "conn:" << conn.get();
        conn->send("hello,world!\n");
    });
    loop.runAfter(1.0,[&](){
        // cli.disconnect();
        loop.quit();
    });
    loop.loop();
}