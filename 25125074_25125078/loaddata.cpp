#include "loaddata.h"
typedef long long ll;
void loadWalletData(string& filename, Wallets*& list, int& n, int& size) {
	ifstream in(filename, ios::binary);
	if (list != NULL) {
		delete[] list;
		list = NULL;
	}
	if (!in) {
		n = 0;
		size = 10;
		list = new Wallets[size];
		return;
	}
	else {
			in.read(reinterpret_cast<char*>(&n), sizeof(n));
			if (n == 0) size = 10;
			else size = n*2;
				list = new Wallets[size];
	}
	for (int i = 0; i < n; i++) {
		ll IDlength=0;
		in.read(reinterpret_cast<char*>(&IDlength), sizeof(IDlength));
		list[i].ID.resize(IDlength);
		in.read(&list[i].ID[0], IDlength);
		ll Namelength=0;
		in.read(reinterpret_cast<char*>(&Namelength), sizeof(Namelength));
		list[i].Name.resize(Namelength);
		in.read(&list[i].Name[0], Namelength);
		in.read(reinterpret_cast<char*>(&list[i].balance), sizeof(double));
	}
	in.close();
}
void loadExpense_categories(string& filename, Expense_Categories*& list, int& n, int& size) {
	ifstream in(filename, ios::binary);
	if (list != NULL) {
		delete[] list;
		list = NULL;
	}
	if (!in) {
		n = 0;
		size = 10;
		list = new Expense_Categories[size];
		return;
	}
	else {
		in.read(reinterpret_cast<char*>(&n), sizeof(n));
		if (n == 0) size = 10;
		else size = n * 2;
		list = new Expense_Categories[size];
	}
	for (int i = 0; i < n; i++) {
		ll IDlength=0;
		in.read(reinterpret_cast<char*>(&IDlength), sizeof(IDlength));
		list[i].ID.resize(IDlength);
		in.read(&list[i].ID[0], IDlength);
		ll Namelength=0;
		in.read(reinterpret_cast<char*>(&Namelength), sizeof(Namelength));
		list[i].Name.resize(Namelength);
		in.read(&list[i].Name[0], Namelength);
	}
	in.close();
}
void loadIncomeSource(string& filename, Income_Sources*& list, int& n, int& size) {
	if (list != NULL) {
		delete[] list;
		list = NULL;
	}
	ifstream in(filename, ios::binary);
	if (!in) {
		n = 0;
		size = 10;
		list = new Income_Sources[size];
		return;
	}
	else {
		in.read(reinterpret_cast<char*>(&n), sizeof(n));
		if (n == 0) size = 10;
		else size = n * 2;
		list = new Income_Sources[size];
	}
	for (int i = 0; i < n; i++) {
		ll IDlength=0;
		in.read(reinterpret_cast<char*>(&IDlength), sizeof(IDlength));
		list[i].ID.resize(IDlength);
		in.read(&list[i].ID[0], IDlength);
		ll Namelength=0;
		in.read(reinterpret_cast<char*>(&Namelength), sizeof(Namelength));
		list[i].Name.resize(Namelength);
		in.read(&list[i].Name[0], Namelength);
	}
	in.close();
}
void loadIncomeData(string& filename, Income_Management*& list, int& n, int& size) {
	if (list != NULL) {
		delete[] list;
		list = NULL;
	}
	ifstream in(filename, ios::binary);
	if (!in) {
		n = 0;
		size = 10;
		list = new Income_Management[size];
		return;
	}
	else {
		in.read(reinterpret_cast<char*>(&n), sizeof(n));
		if (n == 0) size = 10;
		else size = n * 2;
		list = new Income_Management[size];
	}
	for (int i = 0; i < n; i++) {
		ll Datelength = 0;
		in.read(reinterpret_cast<char*>(&Datelength), sizeof(Datelength));
		list[i].Date.resize(Datelength);
		in.read(&list[i].Date[0], Datelength);
		ll SourceIDLength = 0;
		in.read(reinterpret_cast<char*>(&SourceIDLength), sizeof(SourceIDLength));
		list[i].SourceID.resize(SourceIDLength);
		in.read(&list[i].SourceID[0], SourceIDLength);
		in.read(reinterpret_cast<char*>(&list[i].amount), sizeof(list[i].amount));
		ll WalletIDlength = 0;
		in.read(reinterpret_cast<char*>(&WalletIDlength), sizeof(WalletIDlength));
		list[i].WalletID.resize(WalletIDlength);
		in.read(&list[i].WalletID[0], WalletIDlength);
		ll DescriptionLength = 0;
		in.read(reinterpret_cast<char*>(&DescriptionLength), sizeof(DescriptionLength));
		list[i].Description.resize(DescriptionLength);
		in.read(&list[i].Description[0], DescriptionLength);
	}
	in.close();
}
