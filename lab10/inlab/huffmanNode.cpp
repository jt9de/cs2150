/*
 * Filename: huffmanNode.cpp
 * Jinghui Tian
 * Date: 4.27.2021
 */

#include <string>
#include <iostream>
#include "huffmanNode.h"
#include "heap.h"
using namespace std;
huffmanNode::huffmanNode(){
    freq = 1;
    charc = '0';
    prefix = "";
    leftChild = NULL;
    rightChild = NULL;
}
huffmanNode::huffmanNode(int freqq, char charcc){
	freq = freqq;
	charc = charcc;
    prefix = "";
	leftChild = NULL;
	rightChild = NULL;
}

int huffmanNode::getFreq(){
	return freq;
}
char huffmanNode::getChar(){
	return charc;
}
string huffmanNode::getPrefix(){
    return prefix;
}


huffmanNode* huffmanNode::getLeftChild(){
	return leftChild;
}
huffmanNode* huffmanNode::getRightChild(){
	return rightChild;
}

void huffmanNode::setLeftChild(huffmanNode *left){
	leftChild = left;
}
void huffmanNode::setRightChild(huffmanNode *right){
    rightChild = right;
}

void huffmanNode::setPrefix(string x){
    prefix = x;
}
void huffmanNode::setChar(char x){
    charc = x;
}

