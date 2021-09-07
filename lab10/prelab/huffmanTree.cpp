/*
 * Filename: huffmanTree.cpp
 * Jinghui Tian
 * Date: 4.27.2021
 */


#include <string>
#include <iostream>
#include "huffmanTree.h"
#include "huffmanNode.h"
#include "heap.h"
using namespace std;

heap huffmanTree::convert_huffmanTree(heap heap){
	while(heap.size()>1){
		huffmanNode *node1 = heap.deleteMin();
		huffmanNode *node2 = heap.deleteMin();
		huffmanNode *big = new huffmanNode(node1->getFreq() + node2->getFreq(), '0');
        big -> setLeftChild(node1);
        big -> setRightChild(node2);
		heap.insert(big);
	}
	return heap;
}

void huffmanTree::encode(huffmanNode *node, string code){
    //map<char, string> getPrefix;
	if((!(node -> getLeftChild())) && (!(node -> getRightChild()))){
        if ((char)(node -> getChar()) == ' '){
            cout << "space" << "  " << code << endl;
            node -> setPrefix(code);
            
        }else{
        //getMap.insert( mapPair (node->getChar(), " "));
    	cout << (char)(node -> getChar()) << "  " << code << endl;
        //getPrefix.insert(pair<char, string>('a', "123"));
        node -> setPrefix(code);
        }
  	}
  	if(node -> getLeftChild()){
    	encode(node -> getLeftChild(), code + "0");
  	}
 	if(node -> getRightChild()) {
  	    encode(node -> getRightChild(), code + "1");
  	}
}


