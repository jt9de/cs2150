 /*
bankAccount.cpp
Name: Jinghui Tian
ID: jt9de
Date: 2.19.2020
*/

#include <iostream>
#include <string>
#include "bankAccount.h"

using namespace std;

bankAccount::bankAccount() {

    balance = 0.00;
}

bankAccount::bankAccount(double amount) {
    balance = amount;
}


bankAccount::~bankAccount() {

}

// Regular methods, with return types
double bankAccount::withdraw(double amount){
    if (amount <= balance){
        balance -= amount;
    }
    
    return balance;
}

double bankAccount::deposit(double amount){
    balance += amount;
    return balance;
}

double bankAccount::getBalance() const {
    return balance;
}





