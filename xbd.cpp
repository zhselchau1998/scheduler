#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
    
    bool isOutBinary = false;       //Hex format currently
    bool isFileBinary = false;      //Ascii format currently
    int fileArgIndex = 2;           //Binary format currently

    //First check for args
    if(strcmp(argv[1], "-b") == 0)
        isOutBinary = true;         //Change format to binary
    else
        fileArgIndex = 1;           //Change format to hex
    
    //Second create ifstream 
    string fileName(argv[fileArgIndex]);
    ifstream infile(fileName);

    cout << fileName << "\n";

    //Third put ifstream into sstream
    if(infile){
        stringstream ss;
        ss << infile.rdbuf();
        
        //Fourth determine if the file is ascii or binary
        
        //Fifth read file and convert
        
        //Sixth output result, maybe durring fifth step
        cout << ss.rdbuf();
        
        infile.close();
    }
}
