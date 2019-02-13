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

/* OUT INDEX FORMATTING FUNCTION
        1. For the counter, intialized index as decimal named 'decIndex'. Put in decimal to hex. Make copy of return(which is a string now) called 'hexIndex'.
        2. while(hexIndex.length() < 8):
        3. Add 00s to the front of the string.
*/

int binaryToDecimal(string binaryString){

    double sum = 0;
    reverse(binaryString.begin(), binaryString.end());

    for(int i=0; i<binaryString.length(); i++)
        if(binaryString[i] == '1'){
            sum += pow(2.0, (double)i);
        }
    return (int)sum;    
}

string binaryToAscii(string bin){

    const int dec = binaryToDecimal(bin);
    char noPanic;

    if(dec < 127 && dec > 31) {noPanic=static_cast<char>(dec);}
    else return ".";

    return string(1, noPanic);
    
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

string decimalToHex(int num){
    stringstream ss;
    ss << hex << num;
    return ss.str();
}

string asciiToHex(string asciiString){
    return(binaryToHex(asciiToBinary(asciiString)));
}

string decimalToAddress(int num){
    string hexIndex = decimalToHex(num);
    while(hexIndex.length() < 8) hexIndex.insert(0, "0");
    return hexIndex;
}

string addSpacesToBinary(string binary){
    binary.append("  ");
    binary.insert(40," ");
    binary.insert(32," ");
    binary.insert(24," ");
    binary.insert(16," ");
    binary.insert(8," ");
    return binary;
}

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

int main(int argc, char* argv[]){

    bool isOutBinary = false;       //Hex format currently
    bool isFileBinary = true;       //Binary format currently
    int fileArgIndex = 2;           //Binary format currently

    //First check for args
    if(strcmp(argv[1], "-b") == 0)
        isOutBinary = true;         //Change format to binary
    else
        fileArgIndex = 1;           //Change format to hex

    //Second create ifstream and check if file is a binary file
    string fileName(argv[fileArgIndex]);
    stringstream ss;
    if(strcmp(fileName.substr(fileName.length()-4, 4).c_str(), ".txt")==0){
        isFileBinary = false;
        ifstream infile(fileName.c_str());
        ss << infile.rdbuf();
        infile.close();
    }
    else{
        ifstream infile(fileName.c_str(), ios::binary);
        ss << infile.rdbuf();
        infile.close();
    }

    //Third put ifstream into sstream
    if(true){
            string ssLine;              //Each line in file
            string fullText(ss.str());            //Every character in file

        //Fifth read file and convert
        string asciiText = "";
        string hexText = "";
        string binaryText = "";
        int chunkLength = 0;  //Counts chars in chuck
        int charPointer = 0; //Points to current char in fullText

        /* Algorithm's output: 3(or 2) strings named:
          1. asciiText
          2. hexText
          3. binaryText
        */
        

        if(isFileBinary){
            
            //Converting file to binary
            for(int i=0; i<fullText.length(); i++)
                binaryText.append(asciiToBinary(("" + fullText[i])));
            
            while(charPointer < binaryText.length()){
                chunkLength = 0;
                string currChunk = "";
                string hex_string = "";
                string binary_chunk = "";
                string ascii_char = "";
                bool tooShortException = false;

                while(chunkLength < 8){ //Creating the chunk of binary
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
        } else{
            
            asciiText = fullText;

            
            while(charPointer < fullText.length()){
                string currChunk = "";
                string ascii_chunk = "";
                string binary_string = "";
                string hex_string = "";

                currChunk.append(1, fullText[charPointer++]);

                if(isOutBinary){
                    ascii_chunk = currChunk;
                    // Convert ascii_chunk to binary_string
                    binary_string = asciiToBinary(ascii_chunk);
                    // Append binary_string to binaryText
                    binaryText.append(binary_string);
                }else{
                    ascii_chunk = currChunk;
                    // Convert 'ascii_chunk' to 'hex_string'
                    hex_string = asciiToHex(ascii_chunk);
                    // Append hex_string to hexText
                    hexText.append(hex_string);
                }

            }
        }

        /*~ isFileBinary = True:
          Make a copy of fullText called binaryText.
          While loop for taking 8 char chunk after checking if the string has 8 chars avail.
          1 Put 8 char chunk in 'binary_chunk' and make a copy of 'binary_chunk' named 'binary_string'.
          1.b If isOutBinary = True, put 8 char chunk in 'binary_chunk'.
          2. Convert that 'binary_chunk' into 'hex_string' and 'binary_string'into 'Ascii_char'. If not convertable to Ascii, put the character '.'.
          2.b Convert 'binary chunk' to 'Ascii_char'. If not convertable to Ascii, put the character '.'.
          3. Put 'hex_string' in hexText and 'Ascii_char' in asciiText.
          3.b We already have a copy called binaryText. Put 'Ascii_char' in asciiText.*/

        /* ~ isFileBinary = False:
          Make a copy of fullText called asciiText.
          While loop taking 2 char chunk after checking if the string has 2 chars avail.
          1. Put 2 char chunk in 'ascii_chunk'
          1.b If isOutBinary = True, Put 2 char chunk in 'ascii_chunk'.
          2. Convert 'ascii_chunk' to 'hex_string'.
          2.b Convert 'ascii_chunk' to 'hex_string' and then 'hex_string' to 'binary_string'.
          3. Put 'hex_string' to hexText. We already have asciiText.
          3.b Put 'binary_string' to binaryText. We already have asciiText. */

        //Sixth output result

        /* OUTPUT FORMAT: I = Index column, h = hex, b = binary and a = ascii

        if isOutBinary = False;
        // Need a decimal counter for getting correct hex address.
        // 
        IIIIIII hhhh hhhh hhhh hhhh hhhh hhhh hhhh hhhh aaaaaaaaaaaaaaaa

        if isOutBinary = True
        // Need a decimal counter for getting correct hex address.
        IIIIIII bbbbbbbb bbbbbbbb bbbbbbbb bbbbbbbb bbbbbbbb bbbbbbbb aaaaaa */

        if(isOutBinary){
            int address = 0;
            int binaryCounter = 0;
            int asciiCounter = 0;
            string asciiTextClone = asciiText;
            string binaryTextClone = binaryText;
            string binaryLine = ""; // contains 8 char of binary in a word which appears 6 times.
            string asciiLine = ""; // contains 6 chars of ascii
            //Fixing texts so that we dont have any special cases
            for(int i = binaryText.length() % 48; i < 48; i++) {
                if(i==0)break;
                binaryTextClone.append(" "); 
            }
            for(int i = asciiTextClone.length() % 6; i < 6; i++){
                if(i==0)break;
                asciiTextClone.append(" ");
            }

            //For each line
            for(int i = 0; i < asciiTextClone.length(); i += 6){

                binaryLine = addSpacesToBinary(binaryTextClone.substr(i*8, 48));
                asciiLine = asciiTextClone.substr(i, 6);

                //First output <address_>
                cout << decimalToAddress(address) << ": ";

                //Second output binary line
                cout << binaryLine << " ";

                //Third output asciiLine
                cout << asciiLine << endl;

                address += 6;//Incrementing the address
            }

        }else{
            int address = 0;
            int hexCounter = 0;
            int asciiCounter = 0;
            string asciiTextClone = asciiText;
            string hexTextClone = hexText;
            string hexLine = ""; // contains 4 char of hex in a word which appears 8 times.
            string asciiLine = ""; // contains 16 chars of ascii
            // fix text so that we dont have any special cases
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
                cout << decimalToAddress(address) << ":" << " " << hexLine << " " << asciiLine << "\n";
                address += 16;//Incrementing the address
            }

        }

        //cout << asciiText << endl;         //Testing SS
    }
}
