/*
 * Filename: hashTable.cpp
 * Author: Jinghui Tian
 * Date: 3.29.2020
 */
#include "hashTable.h"

bool hashTable::checkprime(unsigned int p) {
    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}


hashTable::hashTable(){
    size = 0;
};

hashTable::hashTable(unsigned int sizee){
    size = getNextPrime(sizee * 2);
    listhere.resize(size, " ");
};
void hashTable::insert(string word){
    unsigned int hashValue = hash(word);
    while (listhere[hashValue] != " "){
        hashValue += 1;
    }
    listhere[hashValue] = word;
};
bool hashTable::find(string word){
    unsigned int hashValue = hash(word);
    while (listhere[hashValue] != " "){
        if (listhere[hashValue] == word){
            return true;
        }else{
            hashValue ++;
    }
    }
    return false;
};

unsigned int hashTable::hash(string word){
    int sum = 0;
    unsigned int hashValue = 0;
    for (int i; i < word.length(); i++){
        sum += word[i];
    }
    hashValue = sum % size;
    return hashValue;
};


