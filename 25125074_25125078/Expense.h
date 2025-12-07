#pragma once
#include <string>
#include <iostream>
#include "Wallets.h"
#include "Expense_categories.h"

using namespace std;

struct Expense_Management {
    string Date;        
    string CategoryID;
    double amount;      
    string WalletID;
    string Description; 
    friend istream& operator>>(istream& in, Expense_Management& a);
    Expense_Management* add(Expense_Management*& list, int& n, int& size,Wallets* wlist, int wcount, Expense_Categories* clist, int ccount);
    Expense_Management* remove(Expense_Management*& list, int& n, Wallets* wlist, int wcount);
};
