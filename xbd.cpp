#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int binaryToDecimal(string binaryString){

    double sum = 0;
    reverse(binaryString.begin(), binaryString.end());

    for(int i=0; i<binaryString.length(); i++)
        if(binaryString[i] == '1'){
            sum += pow(2.0, (double)i);
        }
    return (int)sum;    
}

char binaryToAscii(string bin){

    const int dec = binaryToDecimal(bin);
    char noPanic;

    if(dec < 127 && dec > 31) {noPanic=static_cast<char>(dec);}
    else return '.';

    return noPanic;
    
}

string decimalToBinary(int num){
	string binStr = "";

	while (num > 0)
	{
		binStr = binStr.insert(0, string(1, (char)((num % 2) + 48)));

		num /= 2;
	}

	return binStr;
}

string asciiToBinary(string str){
    string bin = "";
	int strLength = str.length();

	for (int i = 0; i < strLength; ++i)
	{
		string cBin = decimalToBinary(str[i]);
		int cBinLength = cBin.length();

		if (cBinLength < 8) {
			for (size_t i = 0; i < (8 - cBinLength); i++)
				cBin = cBin.insert(0, "0");
		}

		bin += cBin;
	}

	return bin;
}

string binaryToHex(string binaryString){
    string hexString = "";

    for(int i=0; i<2; i++){

        if(strcmp(binaryString.substr(i*4, 4).c_str(),  "0000")== 0) hexString.append("0");
        if(strcmp(binaryString.substr(i*4, 4).c_str(),  "0001")== 0) hexString.append("1");
        if(strcmp(binaryString.substr(i*4, 4).c_str(),  "0010")== 0) hexString.append("2");
        if(strcmp(binaryString.substr(i*4, 4).c_str(),  "0011")== 0) hexString.append("3");
        if(strcmp(binaryString.substr(i*4, 4).c_str(),  "0100")== 0) hexString.append("4");
        if(strcmp(binaryString.substr(i*4, 4).c_str(),  "0101")== 0) hexString.append("5");
        if(strcmp(binaryString.substr(i*4, 4).c_str(),  "0110")== 0) hexString.append("6");
        if(strcmp(binaryString.substr(i*4, 4).c_str(),  "0111")== 0) hexString.append("7");
        if(strcmp(binaryString.substr(i*4, 4).c_str(),  "1000")== 0) hexString.append("8");
        if(strcmp(binaryString.substr(i*4, 4).c_str(),  "1001")== 0) hexString.append("9");
        if(strcmp(binaryString.substr(i*4, 4).c_str(),  "1010")== 0) hexString.append("A");
        if(strcmp(binaryString.substr(i*4, 4).c_str(),  "1011")== 0) hexString.append("B");
        if(strcmp(binaryString.substr(i*4, 4).c_str(),  "1100")== 0) hexString.append("C");
        if(strcmp(binaryString.substr(i*4, 4).c_str(),  "1101")== 0) hexString.append("D");
        if(strcmp(binaryString.substr(i*4, 4).c_str(),  "1110")== 0) hexString.append("E");
        if(strcmp(binaryString.substr(i*4, 4).c_str(),  "1111")== 0) hexString.append("F");
        
    }

    return hexString;
}

string asciiToHex(string asciiString){
    return(binaryToHex(asciiToBinary(asciiString)));
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
                if(isFileBinary && (ssLine[i] == '1' || ssLine[i] == '0' ))//add "|| ssLine[i] == ' '" to end of if statement if spaces do not make a binary file ascii
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
                string hex_string;
                string binary_chunk;

                while(chunkLength < 8){ //Creating the chunk of binary
                    if(fullText[charPointer] == ' ') continue;
                    currChunk.append(fullText[charPointer++]);
                    chunkLength++;
                }
                if(isOutBinary){
                    binary_chunk = currChunk;

                }
                else{
                    binary_string = currChunk;

                }
            }
        } else{
            
            asciiText = fullText;

            
            while(){
                string currChunk = "";
                string ascii_chunk = "";
                string binary_string = "";
                string hex_string = "";

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
