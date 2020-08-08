#include <iostream>

int dynload();

int main()
{
  std::cout << "Hello world!" << '\n';

  dynload();

  return 0;
}
