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

  void *fp2 = dynload.fpget( "func2" );
  typedef int (func_ptr2) ( const float, float *);
  func_ptr2 *func2;
  *(void **)(&func2) = fp2;


  int count;
  float vel = 0.0f;
  for( count = 0; count< 10; count++ ){
    func2(  1.0f, &vel );
    printf("%.1f\n", vel );
  }
  for( count = 0; count< 10; count++ ){
    func2( -1.0f, &vel );
    printf("%.1f\n", vel );
  }


  return 0;
}
