#variables
CC=g++

export PATH="./:$PATH"

all: xbd
     $(CC) xbd.cpp -o xbd

clean:
     rm -rf xbd
    

