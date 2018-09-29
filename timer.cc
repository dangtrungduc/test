
/**************************************************************************
 *
 *    Filename  :  loop.cc
 *    Purpose   :  test 
 *    Created   :  29/09/2018 13:41:46
 *    Author    :  Duc,Dang
 *    Company   :  Viettel
 *    Notes     :
 *
 **************************************************************************/

#include "Logger.h"
#include "EventLoop.h"

using namespace ev;

int main()
{
    EventLoop loop;

    loop.runEvery(1s, [](){
        INFO("run every 1s");
    });
    loop.runAfter(10s, [&](){
        INFO("end after 10s");
        loop.quit();
    });
    loop.runAt(clock::nowAfter(15min), [&](){
        INFO("run 15min later");
    });

    INFO("start looping");
    loop.loop();
}

