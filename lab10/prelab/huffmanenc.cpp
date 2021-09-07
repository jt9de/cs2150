/*
 * Filename: huffmanenc.cpp
 * Jinghui Tian
 * Date: 4.27.2021
 */

#include <string>
#include <iostream>
#include "huffmanNode.h"
#include "heap.h"
#include "huffmanTree.h"
using namespace std;

int main(int argc, char **argv){
    
    FILE *fp = fopen(argv[1], "r");
    
    int freq[126] = {0};
    char charc;
    int total = 0;
    
    
    //count
    while((charc = fgetc(fp)) != EOF){
        int ascii;
        ascii = (int) charc;
        if(ascii < 127 && ascii > 31){
            freq[ascii]++;
            total++;
        }
        
    }


    //build binary heap
    heap heap_here;
    for (int i = 0; i < 126; i++){
        if (freq[i] != 0){
            heap_here.insert(new huffmanNode(freq[i], (char) i));
        }
    }
    
    //print out prefix of letters
    huffmanTree *tree_here = NULL;
    heap final_heap;

    final_heap = tree_here -> convert_huffmanTree(heap_here);
    huffmanNode *node_here = final_heap.findMin();
    tree_here -> encode(node_here, "");
    
    cout << "----------------------------------------" << endl;
    
    //map <char, string> mapp = tree_here -> getMap();
    rewind(fp);
    int comp = 0;
    vector<huffmanNode*> vector_here = heap_here.getArray();
    
     while((charc = fgetc(fp)) != EOF){
         for(int i=1; i <= heap_here.size(); i++){
             //cout << vector_here[i] -> getChar() << endl;
             if(vector_here[i]->getChar() == charc){
                 //cout << "character: " << ()vector_here[i]->getChar() << endl;
                 cout << vector_here[i]->getPrefix() << " ";
                 comp += vector_here[i]->getPrefix().size();
             }
              
      }
      }
     

    cout << endl;
    cout << "----------------------------------------" << endl;
    
    cout << "There are a total of " << total << " symbols that are encoded." << endl;
    cout << "There are "<< heap_here.size() <<  " distinct symbols used." << endl;
    cout << "There were " << total * 8 << " bits in the original file." << endl;
    cout << "There were " << comp << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << (float)(total*8)/comp << " ." << endl;
    cout << "The cost of the Huffman tree is " << (float)comp/total << " bits per character." << endl;
    
    
}
