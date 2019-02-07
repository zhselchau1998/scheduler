#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
    
    bool isOutBinary = false;
    int fileArgIndex = 2;

    //First check for args
    if(argc == 3)
        if(strstr(argv[1], "-b") == 0)
            isOutBinary = true;    //Change format to binary
        else
            fileArgIndex = 1;   //Filler for now
    
    //Second create ifstream 
    string fileName(argv[fileArgIndex]);
    ifstream infile(fileName);

    //Third put ifstream into sstream
    if(file){
        stringstream ss;
        ss << infile.rdbuf();
        
        //Fourth determine if the file is ascii or binary
        
        //Fifth read file and convert
        
        //Sixth output result, maybe durring fifth step
        infile.close();
    }
}
