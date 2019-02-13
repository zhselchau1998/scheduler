#variables
CC=g++

all: xbd
     $(CC) xbd.cpp -o xbd

clean:
     rm -rf xbd
    

