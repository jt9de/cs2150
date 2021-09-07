
/*
 * Filename: TreeCalc.cpp
 * Author: Jinghui Tian
 * Date: 3.23.2020
 */
#include "TreeCalc.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
    stack <TreeNode*> expressionStack;
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
    cleanTree(expressionStack.top());

}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
    if (tree == NULL){
        delete tree;
    }
    else{
        cleanTree(tree -> left);
        cleanTree(tree -> right);
        delete tree;
    }
    
}


// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
    // insert a value into the tree
    TreeNode *exp = new TreeNode(val);
    if (isdigit(val.back())){
        //cout << "inserted a number" << endl;
        expressionStack.push(exp);
    }else {
        //cout << "inserted an operator" << endl;
        exp -> right = expressionStack.top();
        expressionStack.pop();
        exp -> left = expressionStack.top();
        expressionStack.pop();
        expressionStack.push(exp);
    }

    //delete exp;
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
    if (tree != NULL){
        cout << tree -> value << " ";
        printPrefix(tree -> left);
        printPrefix(tree -> right);
    }
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
    // print tree in infix format with appropriate parentheses
    if (tree != NULL){
        if (tree -> left == NULL && tree -> right == NULL){
            cout << tree -> value;
            //cout << endl << "it's an operator";
            
        }else{
            cout << '(';
            printInfix(tree -> left);
            cout << " " << tree -> value << " ";
            //cout << endl << "it's a number";
            printInfix(tree -> right);
            cout << ')';
    }
    }
    
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
    // print the tree in postfix form
    if (tree != NULL){
        printPostfix(tree -> left);
        printPostfix(tree -> right);
        cout << tree -> value << " ";
    }
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
    // Traverse the tree and calculates the result
                if (tree -> left == NULL && tree -> right ==NULL){
                    //cout << "111" << endl;
                    return atoi((tree -> value).c_str());
                }
                else{
                    if (tree -> value == "+"){
                        //cout << "+++" << endl;
                        return calculate(tree -> left) + calculate (tree -> right);
                    }
                    else if (tree -> value == "-"){
                        return calculate(tree -> left) - calculate (tree -> right);
                        
                    }
                    else if (tree -> value == "*"){
                        return calculate(tree -> left) * calculate (tree -> right);
                        
                    }
                    else if (tree -> value == "/"){
                        return calculate(tree -> left) / calculate (tree -> right);
                        
                    }
                    return 0;
                    //cout << "debug1" << endl;
                }

    //cout << "debug" << endl;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    // call private calculate method here
    /*
     int here = calculate(expressionStack.top());
     delete expressionStack.top();
     return here;
     */
    return calculate(expressionStack.top());
    
}
