#pragma once
#include <string>
#include <ctime>
#include "Income.h"
#include "Expense.h"
using namespace std;

struct Income_Management;
struct Expense_Management;

struct StatPair {
    string ID;   
    double total;
};

struct MonthlyNet {
    double month[12];
};

namespace Statistics {
    time_t parseDate(const string &ddmmyyyy);
    double totalIncomeBetween(Income_Management* incomes, int incCount, time_t from, time_t to, const string& walletID = "");
    double totalExpenseBetween(Expense_Management* expenses, int expCount, time_t from, time_t to, const string& walletID = "");
    StatPair* expenseByCategory(Expense_Management* expenses, int expCount, time_t from, time_t to, int &outCount);
    StatPair* incomeBySource(Income_Management* incomes, int incCount, time_t from, time_t to, int &outCount);
    MonthlyNet monthlyNetForYear(Income_Management* incomes, int incCount, Expense_Management* expenses, int expCount, int year);
    StatPair* walletSummary(Income_Management* incomes, int incCount, Expense_Management* expenses, int expCount, time_t from, time_t to, int &outCount);

} 
