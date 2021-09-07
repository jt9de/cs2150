/*
 * Filename: postfixCalculator.cpp
 * Author: Jinghui Tian
 * Date: 3.1.2020
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <string>
#include "postfixCalculator.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
postfixCalculator::postfixCalculator(){
    stack<int> stackhere;
}
postfixCalculator:: ~postfixCalculator(){

}

bool postfixCalculator::isOperand(string x){
    return (isdigit(x.back()));
}


int postfixCalculator::calculate(int a, int b, string operatorhere){
    if (operatorhere == "+"){
        return a + b;
    }
    else if (operatorhere == "-"){
        return a - b;
    }
    else if (operatorhere == "*"){
        return a * b;
    }
    else if (operatorhere == "/"){
        return a / b;
    }
    else if (operatorhere == "~"){
        return b * -1;
    }
    return 0;
}
int postfixCalculator::finalValuehere(string token){
    
        if (isOperand(token)){
            int value = stoi(token);
            stackhere.push(value);
        }
        else if (token == "~"){
            //cout<<"~ detected";
            if (!stackhere.empty()){
                //cout<<"not empty";
                            int b = stackhere.top();
                            stackhere.pop();
                            stackhere.push(calculate(0, b, token));
                        }else{
                            //cout<<"empty stack";
                            exit(-1);
                        }
        }
            
        else if (token == "+" or "-" or "*" or "/"){
            if (!stackhere.empty()){
                            int b = stackhere.top();
                            stackhere.pop();
                            int a = stackhere.top();
                            stackhere.pop();
                            stackhere.push(calculate(a, b, token));
                        }else{
                            exit(-1);
                        }
        }
        


    
        return stackhere.top();
};
