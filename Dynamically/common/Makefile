
all:
	g++ -Wall -fPIC -c *.cpp
	gcc -shared -Wl,-soname,libcommon.so -o libcommon.so.1.0  *.o 
	ln -fs libcommon.so.1.0  libcommon.so

