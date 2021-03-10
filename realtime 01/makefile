# Build the subroutines
all:
	echo
	echo "building sub/basic1.cpp"
	g++ -fPIC -c sub/basic1.cpp -o sub/basic1.o
	
	echo
	echo "building shared lib"
	g++ -shared -Wl,-soname,libbasic1.so.1 -o sub/libbasic1.so.1.0  sub/basic1.o
	ln -sf libbasic1.so.1.0 sub/libbasic1.so.1
	ln -sf libbasic1.so.1.0 sub/libbasic1.so

# Build main:
	g++ main.cpp dynload.cpp -ldl

# Run:  ./a.exe

# Clean
clean:
	find . -name \*.o
	find . -name \*.o -exec rm -rf {} \;
	find . -name \*.so
	find . -name \*.so -exec rm -rf {} \;
	find . -name \*.0 -exec rm -rf {} \;
	find . -name \*.1 -exec rm -rf {} \;

