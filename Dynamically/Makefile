export LD_LIBRARY_PATH=./

all:
	make -C ./common
	make -C ./api
	g++ -o test main.cpp -L ./common -lcommon   -L ./api -lapi
	cp ./common/*.so* ./
	cp ./api/*.so* ./
	./test
