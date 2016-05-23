
all:
	g++ -Wall -fPIC -c *.cpp
	gcc -shared -Wl,-soname,libapi.so -o libapi.so.1.0   *.o  -L../common/  -lcommon  
	ln -fs libapi.so.1.0  libapi.so
