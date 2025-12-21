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
			in.read((char*)(&n), sizeof(n));
			if (n == 0) size = 10;
			else size = n*2;
				list = new Wallets[size];
	}
	for (int i = 0; i < n; i++) {
		ll IDlength=0;
		in.read((char*)(&IDlength), sizeof(IDlength));
		list[i].ID.resize(IDlength);
		in.read(&list[i].ID[0], IDlength);
		ll Namelength=0;
		in.read((char*)(&Namelength), sizeof(Namelength));
		list[i].Name.resize(Namelength);
		in.read(&list[i].Name[0], Namelength);
		in.read((char*)(&list[i].balance), sizeof(double));
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
		in.read((char*)(&n), sizeof(n));
		if (n == 0) size = 10;
		else size = n * 2;
		list = new Expense_Categories[size];
	}
	for (int i = 0; i < n; i++) {
		ll IDlength=0;
		in.read((char*)(&IDlength), sizeof(IDlength));
		list[i].ID.resize(IDlength);
		in.read(&list[i].ID[0], IDlength);
		ll Namelength=0;
		in.read((char*)(&Namelength), sizeof(Namelength));
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
		in.read((char*)(&n), sizeof(n));
		if (n == 0) size = 10;
		else size = n * 2;
		list = new Income_Sources[size];
	}
	for (int i = 0; i < n; i++) {
		ll IDlength=0;
		in.read((char*)(&IDlength), sizeof(IDlength));
		list[i].ID.resize(IDlength);
		in.read(&list[i].ID[0], IDlength);
		ll Namelength=0;
		in.read((char*)(&Namelength), sizeof(Namelength));
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
		in.read((char*)(&n), sizeof(n));
		if (n == 0) size = 10;
		else size = n * 2;
		list = new Income_Management[size];
	}
	for (int i = 0; i < n; i++) {
		ll Datelength = 0;
		in.read((char*)(&Datelength), sizeof(Datelength));
		list[i].Date.resize(Datelength);
		in.read(&list[i].Date[0], Datelength);
		ll SourceIDLength = 0;
		in.read((char*)(&SourceIDLength), sizeof(SourceIDLength));
		list[i].SourceID.resize(SourceIDLength);
		in.read(&list[i].SourceID[0], SourceIDLength);
		in.read((char*)(&list[i].amount), sizeof(list[i].amount));
		ll WalletIDlength = 0;
		in.read((char*)(&WalletIDlength), sizeof(WalletIDlength));
		list[i].WalletID.resize(WalletIDlength);
		in.read(&list[i].WalletID[0], WalletIDlength);
		ll DescriptionLength = 0;
		in.read((char*)(&DescriptionLength), sizeof(DescriptionLength));
		list[i].Description.resize(DescriptionLength);
		in.read(&list[i].Description[0], DescriptionLength);
	}
	in.close();
}
void loadExpenseData(string& filename, Expense_Management*& list, int& n, int& size) {
	if (list != NULL) {
		delete[] list;
		list = NULL;
	}
	ifstream in(filename, ios::binary);
	if (!in) {
		n = 0;
		size = 10;
		list = new Expense_Management[size];
		return;
	}
	else {
		in.read((char*)(&n), sizeof(n));
		if (n == 0) size = 10;
		else size = n * 2;
		list = new Expense_Management[size];
	}
	for (int i = 0; i < n; i++) {
		ll Datelength = 0;
		in.read((char*)(&Datelength), sizeof(Datelength));
		list[i].Date.resize(Datelength);
		in.read(&list[i].Date[0], Datelength);
		ll categoryIDlength = 0;
		in.read((char*)(&categoryIDlength), sizeof(categoryIDlength));
		list[i].CategoryID.resize(categoryIDlength);
		in.read(&list[i].CategoryID[0], categoryIDlength);
		in.read((char*)(&list[i].amount), sizeof(list[i].amount));
		ll WalletIDlength = 0;
		in.read((char*)(&WalletIDlength), sizeof(WalletIDlength));
		list[i].WalletID.resize(WalletIDlength);
		in.read(&list[i].WalletID[0], WalletIDlength);
		ll DescriptionLength = 0;
		in.read((char*)(&DescriptionLength), sizeof(DescriptionLength));
		list[i].Description.resize(DescriptionLength);
		in.read(&list[i].Description[0], DescriptionLength);
	}
	in.close();
}
void loadRecurringData(string& filename, RecurringManager& rm) {
	ifstream in(filename, ios::binary);
	if (!in) {
		rm.n = 0;
		rm.size = 10;
		rm.list = new RecurringEntry[rm.size];
		return;
	}
	else {
		in.read((char*)(&rm.n), sizeof(rm.n));
		if (rm.n == 0) rm.size = 10;
		else rm.size = rm.n * 2;
		rm.list = new RecurringEntry[rm.size];
	}
	for (int i = 0; i < rm.n; i++) {
		ll IDlength = 0;
		in.read((char*)(&IDlength), sizeof(IDlength));
		rm.list[i].ID.resize(IDlength);
		in.read(&rm.list[i].ID[0], IDlength);
		in.read((char*)(&rm.list[i].isIncome), sizeof(rm.list[i].isIncome));
		ll WalletIDlength = 0;
		in.read((char*)(&WalletIDlength), sizeof(WalletIDlength));
		rm.list[i].WalletID.resize(WalletIDlength);
		in.read(&rm.list[i].WalletID[0], WalletIDlength);
		ll CategoryOrSourceIDlength = 0;
		in.read((char*)(&CategoryOrSourceIDlength), sizeof(CategoryOrSourceIDlength));
		rm.list[i].CategoryOrSourceID.resize(CategoryOrSourceIDlength);
		in.read(&rm.list[i].CategoryOrSourceID[0], CategoryOrSourceIDlength);
		in.read((char*)(&rm.list[i].amount), sizeof(rm.list[i].amount));
		ll DescriptionLength = 0;
		in.read((char*)(&DescriptionLength), sizeof(DescriptionLength));
		rm.list[i].Description.resize(DescriptionLength);
		in.read(&rm.list[i].Description[0], DescriptionLength);
		ll startDatelength = 0;
		in.read((char*)(&startDatelength), sizeof(startDatelength));
		rm.list[i].startDate.resize(startDatelength);
		in.read(&rm.list[i].startDate[0], startDatelength);
		ll endDatelength = 0;
		in.read((char*)(&endDatelength), sizeof(endDatelength));
		rm.list[i].endDate.resize(endDatelength);
		in.read(&rm.list[i].endDate[0], endDatelength);
		in.read((char*)(&rm.list[i].nextDate), sizeof(rm.list[i].nextDate));
		in.read((char*)(&rm.list[i].freq.type), sizeof(rm.list[i].freq.type));
		in.read((char*)(&rm.list[i].freq.interval), sizeof(rm.list[i].freq.interval));
		in.read((char*)(&rm.list[i].occurrences), sizeof(rm.list[i].occurrences));
	}
	in.close();
}

