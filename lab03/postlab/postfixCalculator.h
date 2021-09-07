/*
 * Filename: postfixCalculator.h
 * Author: Jinghui Tian
 * Date: 3.1.2020
 */

#include <iostream>
#include <cstdlib>
#include <cmath>

#include "Stack.h"

using namespace std;

class postfixCalculator{
public:
    postfixCalculator();
	~postfixCalculator();
	int finalValuehere(string line);
	bool isOperand(string x);
	int calculate(int a, int b, string operatorhere);
    Stack stackhere;
    
};
