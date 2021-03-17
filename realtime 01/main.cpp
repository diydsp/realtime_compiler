#include <iostream>

#include "dynload.h"


void try_all_the_stuff( void )
{
  // load lib
  DynLoad dynload( "sub/libbasic1.so" );

  // point to functions
  void *fp;
  fp = dynload.fpget( "basic" );   // can make public
  typedef int (func_ptr) (void);
  func_ptr *func;
  *(void **)(&func) = fp;

  void *fp2;
  fp2 = dynload.fpget( "func2" );
  typedef int (func_ptr2) ( const float, float *);
  func_ptr2 *func2;
  *(void **)(&func2) = fp2;

  // run test loop
  int count;
  float vel = 0.0f;
  for( count = 0; count< 5; count++ ){
    func2(  1.0f, &vel );
    printf("%.1f\n", vel );
  }
  for( count = 0; count< 5; count++ ){
    func2( -1.0f, &vel );
    printf("%.1f\n", vel );
  }

}

int main()
{
  std::cout << "Hello world!" << '\n';

  try_all_the_stuff();

  try_all_the_stuff();
  
  return 0;
}
