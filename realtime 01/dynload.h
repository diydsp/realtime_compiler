#include <iostream>

#include<dlfcn.h>
typedef int (add_func) (int a, int b);
typedef int (hwsub_func) (void);



class DynLoad
{
 private:  
  void *lib_handle;
  add_func * add;
  hwsub_func * hwsub;

 public:
  DynLoad()
  {
    lib_handle = (void *)dlopen("sub/libbasic1.so", RTLD_LAZY);
    if(lib_handle)
    {
      hwsub = (hwsub_func*) dlsym(lib_handle, "basic");
      //add = (add_func*) dlsym(lib_handle, "add");
      if( hwsub )
      {
        hwsub();
        //std::cout << "1 + 2 = %d," << add(1, 2);
      }
      else
      {
        std::cout << "Function entry not found in DLL";
      }
      dlclose(lib_handle);
    }
    else
    {
      std::cout << "Unable to open DLL";
    }
  }

};


