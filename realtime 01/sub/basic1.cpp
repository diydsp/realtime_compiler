#include <iostream>

extern "C"   void basic( void );


extern "C" {
void basic( void )
{
  std::cout << "hello subworld." << '\n';
}
}
