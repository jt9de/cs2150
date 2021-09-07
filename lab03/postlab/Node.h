/*
 * Filename: Node.h
 * Author: Jinghui Tian
 * Date: 3.5.2020
 */
//#ifndef NODE_H
//#define NODE_H

#include <iostream>


using namespace std;

class Node{
public:
	Node();
    
private:

	int data;
	Node *next;
	friend class Stack;
    
};
