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
  DynLoad( const char *so_path )
  {
    lib_handle = (void *)dlopen( so_path, RTLD_LAZY);

    if(lib_handle)
    {
      hwsub = (hwsub_func*) dlsym(lib_handle, "basic");
      if( hwsub )
      {
        hwsub();
        //std::cout << "1 + 2 = %d," << add(1, 2);
      }
      else
      {
        std::cout << "Function entry not found in DLL";
      }
      //dlclose(lib_handle);
    }
    else
    {
      std::cout << "Unable to open DLL";
    }
  }

  void *fpget( const char *func_name )
  {
    void *func_ptr;
    func_ptr = dlsym( lib_handle, func_name );
    //*(void **)(&func_ptr) = dlsym( lib_handle, func_name );
    if( func_ptr )
    {
      std::cout << "found " << func_name << std::endl;
      //func_ptr();
    } else
      {      std::cout << "can not find: " << func_name << std::endl;
      }

    return func_ptr;

  }
  
};


