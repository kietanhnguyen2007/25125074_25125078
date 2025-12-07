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
void saveWalletData(string& filename, Wallets* list, int n);
void saveExpense_categories(string& filename, Expense_Categories* list, int n);
void saveIncomeSource(string& filename, Income_Sources* list, int n);
void saveIncomeData(string& filename, Income_Management* list, int n);
void saveExpenseData(string& filename, Expense_Management* list, int n);