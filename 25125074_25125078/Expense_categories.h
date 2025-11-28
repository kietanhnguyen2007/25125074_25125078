#pragma once
#include <string>
#include <iostream>
#include "utils.h"
using namespace std;
class Expense_Categories {
private:
	string ID;
public:
	string Name;
	Expense_Categories* them(Expense_Categories* A, int &n, int &size);
	Expense_Categories* xoa(Expense_Categories* A, int &n);
	Expense_Categories* edit(Expense_Categories* A, int &n);
	Expense_Categories* move(Expense_Categories* A, int &n);
};