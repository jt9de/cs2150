/*
 * Filename: binary_heap.cpp
 * Date: 4.27.2021
 * original code from lecture slides
 * modified by Jinghui Tian
 */

// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "huffmanNode.h"
using namespace std;

class heap {
public:
    heap();
    heap(vector<huffmanNode*> vec);
    ~heap();

    void insert(huffmanNode* x);
    huffmanNode* findMin();
    huffmanNode* deleteMin();
    unsigned int size();
    void makeEmpty();
    bool isEmpty();
    void print();
    vector<huffmanNode*> getArray();

private:
    vector<huffmanNode*> heapp;
    unsigned int heap_size;

    void percolateUp(int hole);
    void percolateDown(int hole);
};

#endif
