/*
 xToN.cpp
 Name: Jinghui Tian
 ID: jt9de
 Date: 2.16.2020
 */
#include <iostream>
using namespace std;

int xton (int a, int b) {
    if (b == 0){
    	return 1;
    }

    return a * xton(a, b-1);

    
}

int main () {
    int x, y, z;
    cin >> x;
    cin >> y;
    z = xton(x, y);
    cout << z << endl;
    return 0;
}
