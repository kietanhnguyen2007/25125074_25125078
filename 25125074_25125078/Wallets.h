#pragma once
#include <string>
#include <iostream>
#include "utils.h"
using namespace std;
struct Wallets {
	string ID;
	string Name;
	double balance;
	Wallets* them(Wallets* A, int &n, int &size);
	Wallets* xoa(Wallets* A, int &n);
	Wallets* edit(Wallets* A, int &n);
	Wallets* move(Wallets* A, int &n);
};