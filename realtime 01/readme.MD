# Build the subroutines

g++ -fPIC -c sub/basic1.cpp

g++ -shared -Wl,-soname,libbasic1.so.1 -o libbasic1.so.1.0  basic1.o

ln -sf libbasic1.so.1.0 libbasic1.so.1

ln -sf libbasic1.so.1.0 libbasic1.so

# Build main:

g++ main.cpp dynload.cpp

# Run:

./a.exe

