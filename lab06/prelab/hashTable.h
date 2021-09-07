/*
 * Filename: hashTable.h
 * Author: Jinghui Tian
 * Date: 3.29.2020
 */
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class hashTable {
public:
    hashTable();
    hashTable(unsigned int sizee);
    void insert(string word);
    bool find(string word);
    unsigned int hash(string word);
    bool checkprime(unsigned int p);
    int getNextPrime (unsigned int n);
    

private:
    
    int size;
    vector<string> listhere;


};


#endif
