#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
    
    bool isOutBinary = false;       //Hex format currently
    bool isFileBinary = true;      //Binary format currently
    int fileArgIndex = 2;           //Binary format currently

    //First check for args
    if(strcmp(argv[1], "-b") == 0)
        isOutBinary = true;         //Change format to binary
    else
        fileArgIndex = 1;           //Change format to hex
    
    //Second create ifstream 
    string fileName(argv[fileArgIndex]);
    ifstream infile(fileName);

    //Third put ifstream into sstream
    if(infile){
        stringstream ss;
        ss << infile.rdbuf();
        string ssLine;
        
        //Fourth determine if the file is ascii or binary
        getline(ss, ssLine);
        for(int i = 0; i < ssLine.length(); i++){
            //If this char is not a 1 or 0 then set file as ascii and break
            if(ssLine[i] == '1' || ssLine[i] == '0')
                continue;
            isFileBinary = false;
            break;
        }

        //Fifth read file and convert
        
        //Sixth output result, maybe durring fifth step
        cout << ssLine << endl;         //Testing SS
        
        infile.close();
    }
}
