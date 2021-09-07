
/*
 * Filename: inlab4.cpp
 * Author: Jinghui Tian
 * Date: 3.16.2020
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <climits>
#include <cfloat>
#include <stdio.h>

using namespace std;
void tableDump(string (*arr)[5], string (*arr1)[4]);
string convertToString(string here11){
    for (int i = here11.length()-1; i >= 0; i--){
        if ((here11.length()-i + 1) % 4 == 0 && i != 0 && i != here11.length()){
            here11.insert(i, ",");
        }
    }
    return here11;
    
}
string littleToBig(string here){
    int n = here.length();
    while (n<2){
        here.insert(0, "0");
        n++;
    }
    for (int i = 0; i < n / 2; i ++){
        swap(here[i], here[n-i-1]);
    }
    return here;
}

int main(){

	// Replace the empty strings below with
	// the values you found while experimenting.

	string nonPointers[6][5] = {
        
		{"int", std::to_string(sizeof(int)) /*size*/, convertToString(std::to_string(INT_MAX)) /*max value*/, "0x00000000" /*zero as stored in hex*/,"0x00000001" /*one as stored in hex*/},
		{"unsigned int", std::to_string(sizeof(unsigned int)) /*size*/, convertToString(std::to_string(UINT_MAX)) /*max value*/, "0x00000000" /*zero as stored in hex*/, "0x00000001" /*one as stored in hex*/},
		{"float", std::to_string(sizeof(float)) /*size*/, "2^128" /*max value*/, "0x00000000" /*zero as stored in hex*/,"0x3f800000"  /*one as stored in hex*/},
		{"double", std::to_string(sizeof(double)) /*size*/, "2^1024" /*max value*/, "0x0000000000000000" /*zero as stored in hex*/, "0x3ff0000000000000" /*one as stored in hex*/},
		{"char", std::to_string(sizeof(char)) /*size*/,std::to_string(CHAR_MAX) /*max value*/, "0x00" /*zero as stored in hex*/, "0x01" /*one as stored in hex*/},
		{"bool", std::to_string(sizeof(bool)) /*size*/, "1" /*max value*/, "0x00" /*zero as stored in hex*/, "0x01" /*one as stored in hex*/},

	};

	string pointers[3][4] = {
		{"int*",  std::to_string(sizeof(int*))/*size*/, "0xffffffffffffffff" /*max value*/, "0x0000000000000000" /*NULL as stored in hex*/},
		{"char*", std::to_string(sizeof(char*)) /*size*/, "0xffffffffffffffff" /*max value*/, "0x0000000000000000" /*NULL as stored in hex*/},
		{"double*", std::to_string(sizeof(double*)) /*size*/, "0xffffffffffffffff" /*max value*/, "0x0000000000000000" /*NULL as stored in hex*/},
	};

	tableDump(nonPointers, pointers);
	return 0;
}

void tableDump(string (*arr)[5], string (*arr1)[4]){
	for(int i = 0; i < 6; i++){
		printf("Size of %s: %s\n", arr[i][0].c_str(), arr[i][1].c_str());
		printf("Max value of %s: %s\n", arr[i][0].c_str(), arr[i][2].c_str());
		printf("Zero of type %s is stored as: %s\n", arr[i][0].c_str(), arr[i][3].c_str());
		printf("One of type %s is stored as: %s\n", arr[i][0].c_str(), arr[i][4].c_str());
	}

	printf("-----------------------------------------------------------------------------\n");

	for(int i = 0; i < 3; i++){
		printf("Size of %s: %s\n", arr1[i][0].c_str(), arr1[i][1].c_str());
		printf("Max value of %s: %s\n", arr1[i][0].c_str(), arr1[i][2].c_str());
		printf("NULL of type %s is stored as: %s\n", arr1[i][0].c_str(), arr1[i][3].c_str());
	}
}
