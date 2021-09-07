/*
 * Filename: huffmanNode.h
 * Jinghui Tian
 * Date: 4.27.2021
 */

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H
#include <string>
#include <iostream>
using namespace std;

class huffmanNode{
	public:
		huffmanNode(int freqq, char charcc);

		int getFreq();
    	int getChar();
        string getPrefix();
    	huffmanNode* getLeftChild();
    	huffmanNode* getRightChild();

    	void setLeftChild(huffmanNode *left);
        void setRightChild(huffmanNode *right);
        void setPrefix(string x);
    private:
    	int freq;
    	char charc;
        string prefix;
    	huffmanNode* leftChild;
    	huffmanNode* rightChild;

};

#endif
