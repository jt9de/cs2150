/*
bankAccount.h
Name: Jinghui Tian
ID: jt9de
Date: 2.19.2020
*/

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class bankAccount {
public:

    bankAccount();                    // default constructor
    bankAccount(double amount);            // constructor with name parameter
    ~bankAccount();                   // destructor

    double withdraw(double amount); //A method that withdraws the specified amount of money from your bank account.
    
    double deposit(double amount); //A method that deposits the specified amount of money from your bank account.
    
    double getBalance() const; //A method that will return the balance currently in the bank account.

    
private:
    double balance; //A private variable that will hold the amount of money in the bank account.
};

#endif
