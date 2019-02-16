#variables
CC=g++

all: xbd
	$(CC) xbd.cpp -o xbd
	export PATH="./:$PATH"

clean:
	rm -rf xbd
    

