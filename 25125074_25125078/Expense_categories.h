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
class Income_Sources {
private:
	string ID;
public:
	string Name;
	Income_Sources* them(Income_Sources* A, int n, int size);
	Income_Sources* xoa(Income_Sources* A, int n);
	Income_Sources* edit(Income_Sources* A, int n, int id);
	Income_Sources* move(Income_Sources* A, int n, int id);
};
class Wallets {
private:
	string ID;
public:
	string Name;
	double balance;
	Wallets* them(Wallets* A, int n, int size);
	Wallets* xoa(Wallets* A, int n);
	Wallets* edit(Wallets* A, int n, int id);
	Wallets* move(Wallets* A, int n, int id);
};