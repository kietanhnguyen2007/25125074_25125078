#pragma once
#include <string>
#include <iostream>
#include "Wallets.h"
#include "Income_Sources.h"
using namespace std;
struct Income_Management {
	string Date;
	string SourceID;
	double amount;
	string WalletID;
	string Description;
	friend istream& operator>>(istream& in, Income_Management& a);// dung cin>>a(a thuoc kieu du lieu Income_Management)
	Income_Management* add(Income_Management*& list, int& n, int& size,Wallets* wlist,int wcount,Income_Sources* slist,int scount);// ham them giao dich thu nhap
	Income_Management* remove(Income_Management*& list, int& n, Wallets* wlist, int wcount);//them ham xoa giao dich neu lo co nhap sai 
};