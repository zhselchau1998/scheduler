#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <cstdint>

using namespace std;

string decimalToHex(int num){
    stringstream ss;
    ss << hex << num;
    return ss.str();
}

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

int main(int argc, char* argv[]){

    FILE *fp;
    int c = 0;
    string fullText = "";

    fp = fopen(argv[1], "r");
    while(!feof(fp)){
        c = fgetc(fp);
        cout << c << " ";
        fullText.append(decimalToBinary(c));
        fullText.append(" ");
    }
    cout << endl << fullText << endl;
    fclose(fp);
    
}
