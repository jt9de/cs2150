/*
 * Filename: testPostfixCalc.cpp
 * Author: Jinghui Tian
 * Date: 3.1.2020
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include "postfixCalculator.h"
#include <stdio.h>
#include <stdlib.h>


using namespace std;



int main (){
    string token;
    postfixCalculator here;
    while (cin >> token){
        here.finalValuehere(token);
    }
    cout << here.stackhere.top() << endl;
}
