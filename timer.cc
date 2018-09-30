
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

#include "EventLoop.h"
#include "Logger.h"
#include "ThreadPool.h"
#include <iostream>
#include <thread>

using namespace ev;

struct Foo {
  Foo(int num) : num_(num) {}

  int num() {
    return num_;
  };
  int num_;
};

int main()
{

  Foo foo(10);

  EventLoop loop;

  ThreadPool tp( 2 );

  std::this_thread::sleep_for(2s);

  auto r = tp.push( &Foo::num, &foo );

  std::cout << r.get() << std::endl;

  loop.loop();

}

