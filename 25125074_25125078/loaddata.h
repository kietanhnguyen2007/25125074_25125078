#pragma once
#include <string>
#include <iostream>
#include "Income.h"
#include "Wallets.h"
#include "Expense_categories.h"
#include "Income_Sources.h"
#include "Expense.h"
#include <fstream>
using namespace std;
void loadWalletData(string& filename, Wallets*& list,int &n,int &size);
void loadExpense_categories(string& filename, Expense_Categories*& list,int &n,int &size);
void loadIncomeSource(string& filename, Income_Sources*& list,int &n,int &size);
void loadIncomeData(string& filename, Income_Management*& list, int& n, int& size);
void loadExpenseData(string& filename, Expense_Categories*& list, int& n, int& size);