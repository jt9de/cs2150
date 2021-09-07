/*
 Jinghui Tian
 threexinput.cpp
 4.19.2021
 */
#include "timer.h"
#include <iostream>
#include <cstring>
using namespace std;

extern "C" int threexplusone(int number);

int main(){

	int x;
	// prompt for x
    cout << "Enter a number: ";
	cin >> x;

    // prompt for n
    int n;

    cout << "Enter iterations of subroutine: ";
    cin >> n;

    int result = threexplusone(x);

    timer t;
    t.start();
    for (int i = 0; i < n; i++){
        threexplusone(x);
    }
    t.stop();
    double time = t.getTime();
    cout << "Steps: " << result << endl;
    //cout << "Average Time: " << time / n << endl;

    return 0;

}
