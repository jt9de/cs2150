/*
ListItr.cpp
Name: Jinghui Tian
ID: jt9de
Date: 2.22.2020
*/

#include <iostream>
#include <string>

#include "ListItr.h"


using namespace std;
ListItr::ListItr(){
    current = new ListNode();
    
}
ListItr::ListItr(ListNode* theNode){
    current = new ListNode();
    current -> next = theNode;
    
}
bool ListItr::isPastEnd() const{
    if(current -> next == NULL){
        return true;
    }
    else{
        return false;
    }
}
bool ListItr::isPastBeginning() const{
    if(current -> previous == NULL){
        return true;
    }
    else{
        return false;
    }
}
void ListItr::moveForward(){
    if(current -> next != NULL){
        current = current -> next;
    }
    return;
}
void ListItr::moveBackward(){
    if(current -> previous != NULL){
        current = current -> previous;
    }
    return;
    
}
int ListItr::retrieve() const{
    return current -> value;
}

void printList(List& source, bool forward){
    
    if (forward){
        ListItr start = ListItr(source.first());
        //start.moveForward();
        while (!start.isPastEnd()){
            cout << start.retrieve() << " ";
            start.moveForward();
        }
    }
    else{
        ListItr end = ListItr(source.last());

        while (!end.isPastBeginning()){
            cout << end.retrieve() << " ";
            end.moveBackward();
    }
    cout << endl;
    }
}
