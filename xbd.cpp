#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

int binaryToDecimal(string binaryString){

    int sum = 0;
    reverse(binaryString.begin(), binary_string.end());

    for(int i=0; i<binaryString.length(); i++)
        if(binaryString[i] == '1'){
            sum += 2^i;
        }
    return sum;    
}

string decimalToBinary(int num){
    
}

string hexToBinary(string hexString){
    string binaryText = "";

    for(int i=0; i>4; i++){
        if(i == 2) binaryText.append(' ');
        if(hexString[i] == '0') binaryText.append("0000");
        if(hexString[i] == '1') binaryText.append("0001");
        if(hexString[i] == '2') binaryText.append("0010");
        if(hexString[i] == '3') binaryText.append("0011");
        if(hexString[i] == '4') binaryText.append("0100");
        if(hexString[i] == '5') binaryText.append("0101");
        if(hexString[i] == '6') binaryText.append("0110");
        if(hexString[i] == '7') binaryText.append("0111");
        if(hexString[i] == '8') binaryText.append("1000");
        if(hexString[i] == '9') binaryText.append("1001");
        if(hexString[i] == 'A') binaryText.append("1010");
        if(hexString[i] == 'B') binaryText.append("1011");
        if(hexString[i] == 'C') binaryText.append("1100");
        if(hexString[i] == 'D') binaryText.append("1101");
        if(hexString[i] == 'E') binaryText.append("1110");
        if(hexString[i] == 'F') binaryText.append("1111");
    }

    return binaryText;
}



int main(int argc, char* argv[]){

    bool isOutBinary = false;       //Hex format currently
    bool isFileBinary = true;       //Binary format currently
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
        string ssLine;              //Each line in file
        string fullText = "";            //Every character in file

        //Store the file line by line in a vector
        vector<string> buffer;
        while(getline(ss, ssLine))
            buffer.push_back(ssLine);

        //Fourth determine if the file is ascii or binary
        for(int n = 0; n < buffer.size(); n++){
            ssLine = buffer[n];
            for(int i = 0; i < ssLine.length(); i++){
                //If this char is not a 1 or 0 then set file as ascii and break
                //If file is already confirmed binary break
                if(isFileBinary && (ssLine[i] == '1' || ssLine[i] == '0' || ssLine[i] == ' '))
                    continue;
                isFileBinary = false;
                break;
            }
            fullText.append(ssLine);        //Storing every character in file as a string
        }

        //Fifth read file and convert

        string asciiText;
        string hexText;
        string binaryText;
        int chunkLength = 0;  //Counts chars in chuck
        int charPointer = 0; //Points to current char in fullText

        /* Algorithm's output: 3(or 2) strings named:
          1. asciiText
          2. hexText
          3. binaryText
        */

        if(isFileBinary){
            
            binaryText = fullText;
            
            while(){
                string binary_string;
                string currChunk;
                while(chunkLength < 8){ //Creating the chunk of binary
                    if(fullText[charPointer] == ' ') continue;
                    currChunk.append(fullText[charPointer++]);
                    chunkLength++;
                }
                binary_string = currChunk;

            }
        } else{
            
            asciiText = fullText;

            
            while(){
                string currChunk;
                string ascii_chunk;
                string binary_string;
                string hex_string;

                while(chunkLength < 2){
                    if(fullText[charPointer] == ' ') continue;
                    currChunk.append(fullText[charPointer++]);
                    chunkLength++;
                }

                if(isOutBinary){
                    ascii_chunk = currChunk;
                    // Convert ascii_chunk to binary_string

                    // Append binary_string to binaryText
                }else{

                }
            }
        }

        //~ isFileBinary = True:
          // Make a copy of fullText called binaryText.
          // While loop for taking 8 char chunk after checking if the string has 8 chars avail.
          // 1 Put 8 char chunk in 'binary_chunk' and make a copy of 'binary_chunk' named 'binary_string'.
          // 1.b If isOutBinary = True, put 8 char chunk in 'binary_chunk'.
          // 2. Convert that 'binary_chunk' into 'hex_string' and 'binary_string'into 'Ascii_char'. If not convertable to Ascii, put the character '.'.
          // 2.b Convert 'binary chunk' to 'Ascii_char'. If not convertable to Ascii, put the character '.'.
          // 3. Put 'hex_string' in hexText and 'Ascii_char' in asciiText.
          // 3.b We already have a copy called binaryText. Put 'Ascii_char' in asciiText.

        //~ isFileBinary = False:
          // Make a copy of fullText called asciiText.
          // While loop taking 2 char chunk after checking if the string has 2 chars avail.
          //1. Put 2 char chunk in 'ascii_chunk'
          //1.b If isOutBinary = True, Put 2 char chunk in 'ascii_chunk'.
          //2. Convert 'ascii_chunk' to 'hex_string'.
          //2.b Convert 'ascii_chunk' to 'hex_string' and then 'hex_string' to 'binary_string'.
          //3. Put 'hex_string' to hexText. We already have asciiText.
          //3.b Put 'binary_string' to binaryText. We already have asciiText.

        //Sixth output result, maybe durring fifth step
        cout << fullText << endl;         //Testing SS

        infile.close();
    }
}
