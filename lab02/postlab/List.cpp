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

List::List(const List& source) {
    head=new ListNode();
    tail=new ListNode();
    head->next=tail;
    tail->previous=head;
    count=0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List::~List(){
    
}

List& List::operator=(const List& source) {
    if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

// methods
bool List::isEmpty() const{
    if (head -> next == tail){
        return true;
    }else{
        return false;
    }
}
void List::makeEmpty(){
    head -> next = tail;
    tail -> previous = head;
    count = 0;
}
ListItr List::first(){
    ListItr(current)= head -> next;
    current.moveForward();
    return current;
}
ListItr List::last(){
    ListItr(current)= tail -> previous;
    current.moveForward();
    return current;
}
void List::insertAfter(int x, ListItr position){
    ListNode * new_node = new ListNode();
    new_node -> value = x;
    new_node -> next = position.current -> next;
    position.current -> next = new_node;
    count++;
    
    
    
    
}
void List::insertBefore(int x, ListItr position){
    ListNode * new_node = new ListNode();
    new_node -> value = x;
    new_node -> next = position.current;
    new_node -> previous = position.current -> previous;
    position.current -> previous -> next = new_node;
    position.current -> previous = new_node;
    
    count++;
    
    
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
    count++;
}
ListItr List::find(int x){
    ListItr current = ListItr(head->next);
    current.moveForward();
    if (current.retrieve() != x){
        current.moveForward();
    }else{
        return current;
    }
    
}
void List::remove(int x){
    count--;
    ListItr temp = find(x);
    temp.current -> previous -> next = temp.current -> next;
    temp.current -> next -> previous = temp.current -> previous;
    delete temp.current;
    
    
}
int List::size()const{
    return count;
}
