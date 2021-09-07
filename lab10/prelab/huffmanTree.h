/*
 * Filename: huffmanTree.h
 * Jinghui Tian
 * Date: 4.27.2021
 */

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
#include <string>
#include <iostream>
#include "heap.h"
#include "huffmanNode.h"
using namespace std;

class huffmanTree{
public:
    heap convert_huffmanTree(heap heap);
    huffmanNode *n;
    void encode(huffmanNode *node, string prefix);
    

};

#endif
