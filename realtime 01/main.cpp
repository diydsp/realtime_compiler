#include <iostream>

#include "dynload.h"



int main()
{
  std::cout << "Hello world!" << '\n';

  DynLoad dynload( "sub/libbasic1.so" );
  void *fp = dynload.fpget( "basic" );
  typedef int (func_ptr) (void);
  func_ptr *func;
  *(void **)(&func) = fp;
  func();

  return 0;
}
