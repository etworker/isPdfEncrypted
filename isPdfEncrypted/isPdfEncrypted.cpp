// Check if pdf file is encrypted

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "isPdfEncrypted.h"

using namespace std;

bool isPdfEncrypted(char *filename){
	// read file into string 
	std::ifstream ifs(filename, ios::binary);
	std::stringstream strs;
	strs << ifs.rdbuf();
	std::string str(strs.str());

	// if PDF is encrypted, then "/Encrypt \d+ 0 R/" is insided

	// find "/Encrypt "
	int flagPos = str.find("/Encrypt ");
	if (flagPos == string::npos){
		return false;
	}

	// find " 0 R/"
	int startPos = flagPos + strlen("/Encrypt ");
	int flagPos2 = str.find("0 R/", startPos);
	if (flagPos2 == string::npos){
		return false;
	}

	// check if substring is \d+
	std::string strInt = str.substr(startPos, flagPos2 - startPos);
	int intPos = strInt.find_first_not_of("0123456789");
	if (intPos == string::npos){
		return false;
	}

	// it is encrypted
	return true;
}

int main(int argc, char *argv[]) {
	// make sure args count ok
	if (argc < 2) {
		printf("Usage example: isPdfEncrypted.exe a.pdf\n");
		return 1;
	}

	// check pdf if encrypted
	if (isPdfEncrypted(argv[1])) {
		cout << "encrypted" << endl;
	}
	else{
		cout << "not encrypted" << endl;
	}

	return 0;
}