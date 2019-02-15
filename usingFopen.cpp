#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

string decimalToBinary(int num){
	string binStr = "";

	while (num > 0)
	{
		binStr = binStr.insert(0, string(1, (char)((num % 2) + 48)));

		num /= 2;
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
        cout << c;
        fullText.append(decimalToBinary(c));
    }
    cout << endl << fullText << endl;
    fclose(fp);
    
}
