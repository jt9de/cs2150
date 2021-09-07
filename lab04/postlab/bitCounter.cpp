
/*
 * Filename: bitCounter.cpp
 * Author: Jinghui Tian
 * Date: 3.17.2020
 */

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int bitConverter(int n){
	if (n == 0){
		return 0;
	}else{
		return (n & 1) + bitConverter(n >> 1);
	}
}

int convertTo10(string numberToConvert, int startBase){
	int value = 0;
	int valueEach = 1;
	for (int i = numberToConvert.length() -1; i >= 0; i--){
		char a = numberToConvert[i];
		if (a > '9'){
			a = a - 'A' + 10;
		}else{
			a -= '0';
		}
		value += a * valueEach;
		valueEach = startBase * valueEach;


	}
	return value;
}

string convertToAnyBase(int value, int endBase){
	string finalValue;
	while (value > 0){
		char valueEach = value % endBase;
		if (valueEach > '9'){
			valueEach = valueEach + 'A' - 10;
		}else{
			valueEach += '0';
		}
		finalValue += valueEach;
		value = value / endBase;


	}
	
	int len = finalValue.length();
	for (int i = 0; i < len / 2; i ++){
        swap(finalValue[i], finalValue[len-i-1]);
    }
    return finalValue;

}

string baseConverter(int bitCount, string numberToConvert, int startBase, int endBase){
	return convertToAnyBase(convertTo10(numberToConvert, startBase), endBase);
}

int returnEE(int EE){
	return 34;
}

int main(int argc, char **argv){
	argc = 4;
	cout << argv[1] << " has " << bitConverter(std::atoi(argv[1])) << " bit(s)" << endl;

	cout << argv[2] << " (base " << argv[3] << ") = " << baseConverter(std::stoi(argv[1]), argv[2], std::stoi(argv[3]), std::stoi(argv[4])) << " (base " << argv[4] << ")" << endl;
	//cout << convertToAnyBase(convertTo10(argv[2], std::stoi(argv[3])),std::stoi(argv[4]))  << endl;
	return 0;
	
}