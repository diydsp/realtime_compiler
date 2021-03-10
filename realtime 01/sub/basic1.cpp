#include <iostream>

extern "C"   void basic( void );
//void basic( void );


extern "C" {

void basic( void )
{
  std::cout << "hello subworld." << '\n';
}


  void func2( const float force, float *vel )
  {
    float mass = 0.25f;

    *vel += force / mass;
  }
  
}
