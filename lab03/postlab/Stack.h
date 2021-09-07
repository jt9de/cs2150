/*
 * Filename: Stack.h
 * Author: Jinghui Tian
 * Date: 3.5.2020
 */
//#ifndef STACK_H
//#define STACK_H

#include <iostream>
#include "Node.h"



using namespace std;

class Stack{
public:
	Stack();
    void push(int e);
    void pop();
    int top();
    bool empty();
    

    

private:
	Node *topNode;

};
