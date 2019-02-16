/*****************************************************************************************************
 Name: Zach Selchau
 username: cssc0418
 Project: CS530 Assignment 1
 File: xbd.cpp
 Notes: The sourcecode file containing the functions and code required to run a hex/binarydump program.

 Name: Darpan Beri
 username: cssc0429
 Project: CS530 Assignment 1
 File: xbd.cpp
  Notes: The sourcecode file containing the functions and code required to run a hex/binarydump program.
*******************************************************************************************************/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include "xbd.hpp"


using namespace std;

/*************************************************************
 FUNCTION: binaryToDecimal()
 DESCRIPTION: Converts a binary string to its decimal value.
 I/O:
    input parameters: String of binary
    output: Its integer value. 
 *************************************************************/
int binaryToDecimal(string binaryString){

    double sum = 0;
    reverse(binaryString.begin(), binaryString.end());

    for(int i=0; i<binaryString.length(); i++)
        if(binaryString[i] == '1'){
            sum += pow(2.0, (double)i);
        }
    return (int)sum;    
}

/*************************************************************
 FUNCTION: binaryToAscii()
 DESCRIPTION: Converts a binary string to printable characters.
 I/O:
    input parameters: String of binary
    output: Its converted character, if decimal value < 127 && > 31.
 *************************************************************/
string binaryToAscii(string bin){

    const int dec = binaryToDecimal(bin);
    char noPanic;

    if(dec < 127 && dec > 31) {noPanic=static_cast<char>(dec);}
    else return ".";

    return string(1, noPanic);
    
}

/*************************************************************
 FUNCTION: decimalToHex()
 DESCRIPTION: Converts a decimal int to hex string.
 I/O:
    input parameters: int decimal value
    output: Its converted hex values.
 *************************************************************/
string decimalToHex(int num){
    stringstream ss;
    ss << hex << num;
    return ss.str();
}

/*************************************************************
 FUNCTION: decimalToBinary()
 DESCRIPTION: Converts a decimal int to binary string.
 I/O:
    input parameters: int decimal value
    output: Its converted binary values.
 *************************************************************/
string decimalToBinary(int num){
	string binStr = "";
    string numStr = decimalToHex(num);

    if(numStr.length()==1)numStr = "0" + numStr;

    if(strcmp(numStr.c_str(), "ffffffff")==0) return "";

    for(int i=0; i<numStr.length(); i++){
        if(numStr[i]=='0')binStr.append("0000");
        if(numStr[i]=='1')binStr.append("0001");
        if(numStr[i]=='2')binStr.append("0010");
        if(numStr[i]=='3')binStr.append("0011");
        if(numStr[i]=='4')binStr.append("0100");
        if(numStr[i]=='5')binStr.append("0101");
        if(numStr[i]=='6')binStr.append("0110");
        if(numStr[i]=='7')binStr.append("0111");
        if(numStr[i]=='8')binStr.append("1000");
        if(numStr[i]=='9')binStr.append("1001");
        if(numStr[i]=='a'||numStr[i]=='A')binStr.append("1010");
        if(numStr[i]=='b'||numStr[i]=='B')binStr.append("1011");
        if(numStr[i]=='c'||numStr[i]=='C')binStr.append("1100");
        if(numStr[i]=='d'||numStr[i]=='D')binStr.append("1101");
        if(numStr[i]=='e'||numStr[i]=='E')binStr.append("1110");
        if(numStr[i]=='f'||numStr[i]=='F')binStr.append("1111");
    }	

	return binStr;
}

/*************************************************************
 FUNCTION: asciiToBinary()
 DESCRIPTION: Converts a ascii string to binary string.
 I/O:
    input parameters: ascii string
    output: Its converted binary values.
 *************************************************************/
string asciiToBinary(string str){
    string bin = "";
	int strLength = str.length();

	for (int i = 0; i < strLength; ++i)
	{
		string cBin = decimalToBinary(int(str[i]));
		bin += cBin;
	}

	return bin;
}

/*************************************************************
 FUNCTION: binaryToHex()
 DESCRIPTION: Converts a binary string to hex string.
 I/O:
    input parameters: binary string
    output: Its converted hex values.
 *************************************************************/
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

/*************************************************************
 FUNCTION: asciiToHex()
 DESCRIPTION: Converts a ascii string to hex string.
 I/O:
    input parameters: ascii string
    output: Its converted hex values.
 *************************************************************/
string asciiToHex(string asciiString){
    return(binaryToHex(asciiToBinary(asciiString)));
}

/*************************************************************
 FUNCTION: decimalToAddress()
 DESCRIPTION: Converts a decimal integer to hex string to be 
 used for address in output.
 I/O:
    input parameters: decimal integer
    output: Its converted hex values.
 *************************************************************/
string decimalToAddress(int num){
    string hexIndex = decimalToHex(num);
    while(hexIndex.length() < 7) hexIndex.insert(0, "0");
    return hexIndex;
}

/*************************************************************
 FUNCTION: addSpacesToBinary()
 DESCRIPTION: Adds spaces to binary string so that it becomes 
 ready for output
 I/O:
    input parameters: binary string
    output: readable binary string.
 *************************************************************/
string addSpacesToBinary(string binary){
    binary.append("  ");
    binary.insert(40," ");
    binary.insert(32," ");
    binary.insert(24," ");
    binary.insert(16," ");
    binary.insert(8," ");
    return binary;
}

/*************************************************************
 FUNCTION: addSpacesToHex()
 DESCRIPTION: Adds spaces to Hex string so that it becomes ready for
 output
 I/O:
    input parameters: Hex string
    output: readable Hex string.
 *************************************************************/
string addSpacesToHex(string hex){
    hex.append("  ");
    hex.insert(28," ");
    hex.insert(24," ");
    hex.insert(20," ");
    hex.insert(16," ");
    hex.insert(12," ");
    hex.insert(8," ");
    hex.insert(4," ");
    return hex;
}

/*************************************************************
 FUNCTION: main()
 DESCRIPTION: controls flow of execution of this program
 *************************************************************/
int main(int argc, char* argv[]){

    bool isOutBinary = false;       // Hex format currently
    bool isFileBinary = true;       // Binary format currently
    int fileArgIndex = 2;           // Binary format currently
    string fullText = "";           // Contents of the file in a string
    string asciiText = "";          // Contents of the file as printable characters
    string hexText = "";            // Contents of the file as hex string
    string binaryText = "";         // Contents of the file as binary string

    // Check for args
    if(strcmp(argv[1], "-b") == 0)isOutBinary = true;         // Change format to binary
    else fileArgIndex = 1;           // Change format to hex

    //Takes contents of the file and puts in fullText
    string fileName(argv[fileArgIndex]); 
    FILE *fp;
    int c = 0;

    fp = fopen(argv[fileArgIndex], "r");
    while(!feof(fp)){
        c = fgetc(fp);
        fullText.append(decimalToBinary(c));
    }
    fclose(fp);


    //if(true){
        // Read file and convert
        int chunkLength = 0;    // Counts chars in chuck
        int charPointer = 0;    // Points to current char in fullText
        binaryText = fullText;  // fullText is currently in Binary

        while(charPointer < binaryText.length()){
            chunkLength = 0;
            string currChunk = "";
            string hex_string = "";
            string binary_chunk = "";
            string ascii_char = "";
            bool tooShortException = false;

            while(chunkLength < 8){ // Creating the chunk of binary
                if(charPointer >= binaryText.length()){
                    tooShortException=true;
                    break;
                }
                currChunk.append(1, binaryText[charPointer++]);
                chunkLength++;
            }
            if(tooShortException){
                if(chunkLength >= 4){
                    string specialCase = currChunk.substr(0, 4);
                    asciiText.append(".");
                    hexText.append(binaryToHex(specialCase));
                }else break;
            }
            else if(isOutBinary){
                binary_chunk = currChunk;
                // Convert 'binary_chunk' to 'ascii_char'
                ascii_char = binaryToAscii(binary_chunk);
                // Append ascii_char to asciiText
                asciiText.append(ascii_char);
            }
            else{
                binary_chunk = currChunk;
                // Convert 'binary_chunk' to 'hex_string'
                hex_string = binaryToHex(binary_chunk);
                // Append to hexText
                hexText.append(hex_string);
                // Append to asciiText
                asciiText.append(binaryToAscii(binary_chunk));
            }
                
        }

        if(isOutBinary){
            int address = 0;
            int binaryCounter = 0;
            int asciiCounter = 0;
            string asciiTextClone = asciiText;
            string binaryTextClone = binaryText;
            string binaryLine = ""; // Contains 8 char of binary in a word which appears 6 times.
            string asciiLine = ""; // Contains 6 chars of ascii
            // Fixing texts so that we dont have any special cases
            for(int i = binaryText.length() % 48; i < 48; i++) {
                if(i==0)break;
                binaryTextClone.append(" "); 
            }
            for(int i = asciiTextClone.length() % 6; i < 6; i++){
                if(i==0)break;
                asciiTextClone.append(" ");
            }

            // For each line
            for(int i = 0; i < asciiTextClone.length(); i += 6){

                binaryLine = addSpacesToBinary(binaryTextClone.substr(i*8, 48));
                asciiLine = asciiTextClone.substr(i, 6);

                // First output <address_>
                cout << decimalToAddress(address) << ": ";

                // Second output binary line
                cout << binaryLine;

                // Third output asciiLine
                cout << asciiLine << endl;

                address += 6;// Incrementing the address
            }

        }else{
            int address = 0;
            int hexCounter = 0;
            int asciiCounter = 0;
            string asciiTextClone = asciiText;
            string hexTextClone = hexText;
            string hexLine = ""; // Contains 4 char of hex in a word which appears 8 times.
            string asciiLine = ""; // Contains 16 chars of ascii
            // Fix text so that we dont have any special cases
            for(int i = hexText.length() % 32; i < 32; i++){
                if(i==0)break; 
                hexTextClone.append(" "); // 8*4 = 32
            }

            for(int i = asciiTextClone.length() % 16; i < 16; i++){
                if(i==0)break;
                asciiTextClone.append(" ");
            }

            for(int i = 0; i < asciiTextClone.length(); i += 16){
                hexLine = addSpacesToHex(hexTextClone.substr(i*2, 32));
                asciiLine = asciiTextClone.substr(i, 16);

                // OUTPUT per line
                cout << decimalToAddress(address) << ":" << " " << hexLine << asciiLine << "\n";
                address += 16;// Incrementing the address
            }
        }
    //}
}
/******************************[ EOF: xbd.cpp ]****************************/