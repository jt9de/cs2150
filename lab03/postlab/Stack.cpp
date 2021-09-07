/*
 * Filename: Stack.cpp
 * Author: Jinghui Tian
 * Date: 3.5.2020
 */

#include <iostream>
#include "Stack.h"
#include <string>

using namespace std;
Stack::Stack(){
	topNode = new Node();
}

bool Stack::empty(){
    if(topNode == NULL){
        return true;
    }else{
        return false;
    }
};
    
void Stack::push(int e){
	Node *temp = new Node();
	temp -> data = e;
	temp -> next = topNode;
	topNode = temp;

};
void Stack::pop(){
	Node *temp = NULL;
	if (topNode != NULL){
        temp = topNode;
        topNode = topNode -> next;
        temp -> next = NULL;
    }else{
        exit(-1);
    }
};
int Stack::top(){
	if(Stack::empty()){
        exit(-1);
	}else{
		return topNode -> data;
	}
	
};



