/*
 * Filename: binary_heap.cpp
 * Date: 4.27.2021
 * original code from lecture slides
 * modified by Jinghui Tian
 */

// Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include "heap.h"
#include "huffmanNode.h"

using namespace std;

// default constructor
heap::heap() : heap_size(0) {
    heapp.push_back(0);
}

// builds a heap from an unsorted vector
heap::heap(vector<huffmanNode*> vec) : heap_size(vec.size()) {
    heapp = vec;
    heapp.push_back(heapp[0]);
    heapp[0] = NULL;
    for (int i = heap_size/2; i > 0; i--) {
        percolateDown(i);
    }
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(huffmanNode* x) {
    // a vector push_back will resize as necessary
    heapp.push_back(x);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
    // get the value just inserted
    huffmanNode* node = heapp[hole];
    // while we haven't run off the top and while the
    // value is less than the parent...
    for ( ; (hole > 1) && (node -> getFreq() < heapp[hole/2] -> getFreq()); hole /= 2) {
        heapp[hole] = heapp[hole/2]; // move the parent down
    }
    // correct position found!  insert at that spot
    heapp[hole] = node;
}

huffmanNode* heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }

    // save the value to be returned
    huffmanNode* ret = heapp[1];
    // move the last inserted position into the root
    heapp[1] = heapp[heap_size--];
    // make sure the vector knows that there is one less element
    heapp.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    // get the value to percolate down
    huffmanNode *node = heapp[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (heapp[child+1]->getFreq() < heapp[child]->getFreq())) {
            child++;
        }
        // if the child is greater than the node...
        if (node -> getFreq() > heapp[child] -> getFreq() ) {
            heapp[hole] = heapp[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    heapp[hole] = node;
}

huffmanNode* heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return heapp[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    heapp.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::print() {
    cout << "(" << heapp[0] << ") ";
    for (int i = 1; i <= heap_size; i++) {
        cout << ((char) heapp[i] -> getChar()) << "=" << heapp[i] -> getFreq() << " ";
        // next line from http://tinyurl.com/mf9tbgm
        bool isPow2 = (((i+1) & ~(i))==(i+1))? i+1 : 0;
        if (isPow2) {
            cout << endl << "\t";
        }
    }
    cout << endl;
}

vector <huffmanNode*> heap::getArray(){
    return heapp;
}
