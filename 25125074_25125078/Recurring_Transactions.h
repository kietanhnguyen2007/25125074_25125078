#pragma once
#include <string>
#include <ctime>
#include "Income.h"
#include "Expense.h"
#include "Wallets.h"
#include "Income_Sources.h"
#include "Expense_Categories.h"

using namespace std;

struct Income_Management;   
struct Expense_Management;  
struct Wallets;             
struct Income_Sources;      
struct Expense_Categories;  

const int R_DAILY   = 0;
const int R_WEEKLY  = 1;
const int R_MONTHLY = 2;
const int R_YEARLY  = 3;

struct RecurringFrequency {
    int type;    
    int interval;
};

struct RecurringEntry {
    string ID;                  
    bool isIncome;              
    string WalletID;            
    string CategoryOrSourceID;  
    double amount;
    string Description;
    string startDate;           
    string endDate;             
    time_t nextDate;            
    RecurringFrequency freq;
    int occurrences;            
};

struct RecurringManager {
    RecurringEntry* list;
    int n;      
    int size;   
    RecurringManager();
    ~RecurringManager();
    void add(const RecurringEntry& r);
    bool remove(int idx);
    void listAll() const;
    void processRecurrences(
        time_t upToDate, Income_Management*& incomes, int& incN, int& incSize, Expense_Management*& expenses, int& expN, int& expSize,
        Wallets* wlist, int wcount, Income_Sources* slist, int scount,Expense_Categories* clist, int ccount);
};