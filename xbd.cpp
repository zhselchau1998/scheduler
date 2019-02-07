#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
    
    bool isBinary = false;
    int fileArgIndex = 2;

    //First check for args
    if(argc == 3)
        if(strstr(argv[1], "-b") == 0)
            isBinary = true;    //Change format to binary
        else
            fileArgIndex = 1;   //Filler for now
    
    //Second create ifstream 
    string fileName(argv[fileArgIndex]);
    ifstream file(fileName);
    
}
