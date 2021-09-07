/*
 * Filename: prelab4.cpp
 * Author: Jinghui Tian
 * Date: 3.9.2020
 */

#include <iostream>
#include "prelab4.h"
#include <string>
#include <climits>


using namespace std;
prelab4::prelab4(){
    
}
void prelab4 :: sizeOfTest(){
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of bool: " << sizeof(bool) << endl;
    cout << "Size of int*: " << sizeof(int*) << endl;
    cout << "Size of char*: " << sizeof(char*) << endl;
    cout << "Size of double*: " << sizeof(double*) << endl;
};
void prelab4 :: overflow(){
    unsigned int here;
    here = UINT_MAX;
    cout << here << " + 1 = " << here + 1 << endl;
};
void prelab4 :: outputBinary(unsigned int x){
    string temp;

    for (int i = 1; i<= 32; i++){
        temp += to_string(x % 2);
        x = x / 2;
        if (i % 4 == 0 && i != 32){
            temp += " ";
        }
    }
    int n = temp.length();
    for (int i = 0; i < n / 2; i ++){
        swap(temp[i], temp[n-i-1]);
    }
    cout << temp << endl;
    
};

int main(){
    prelab4 prelab44;
    int inputNumber;
    cin >> inputNumber;
    prelab44.sizeOfTest();
    prelab44.overflow();
    prelab44.outputBinary(inputNumber);
    
    
};


