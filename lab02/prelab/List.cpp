/*
List.cpp
Name: Jinghui Tian
ID: jt9de
Date: 2.22.2020
*/

#include <iostream>
#include <string>
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"

using namespace std;

List::List():count(0){
    head = new ListNode();
    tail = new ListNode();
    head -> previous = NULL;
    head -> next = tail;
    tail -> previous = head;
    tail -> next = NULL;
}

List::List(const List& source){
    
}

List::~List(){
    
}
List& List::operator=(const List& source){
    return *this;
}
// methods
bool List::isEmpty() const{
    return false;
}
void List::makeEmpty(){
    
}
ListItr List::first(){
    return ListItr(head->next);
}
ListItr List::last(){
    return 0;
}
void List::insertAfter(int x, ListItr position){
    
}
void List::insertBefore(int x, ListItr position){
    
}
void List::insertAtTail(int x){
    ListNode * new_node = new ListNode();
    new_node -> value = x;
    
    if(head -> next == tail){
        head -> next = new_node;
        new_node -> next = tail;
        tail -> previous = new_node;
        new_node -> previous = head;
    }
    else{
        new_node -> previous = tail -> previous;
        new_node -> previous -> next = new_node;
        tail -> previous = new_node;
        new_node -> next = tail;
    }
    
}
ListItr List::find(int x){
    return 0;
}
void List::remove(int x){
    
}
int List::size()const{
    return count;
}
