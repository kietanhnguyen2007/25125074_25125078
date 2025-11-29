#include "Income.h"
istream& operator>>(istream& in, Income_Management& a) {
	cout << "\n--- ADD NEW INCOME TRANSACTION ---" << endl;
	while (cin.peek() == '\n') cin.ignore();
	cout << "Enter Date(dd/mm/yyyy): "<< endl;
	getline(in, a.Date);
	cout << "Enter amount: " << endl;
	in >> a.amount;
	cout << "Enter description: ";
	while (cin.peek() == '\n') cin.ignore();
	getline(cin, a.Description);
	return in;
}
Income_Management* Income_Management::add(Income_Management*& list, int& n, int& size, Wallets* wlist, int wcount, Income_Sources* slist, int scount) {
	if (n == size) {
		if (n == 0) size = 1;
		else {
			size = 2 * n;
		}
			Income_Management* NewList = new Income_Management[size];
			for (int i = 0; i < n; i++) {
				NewList[i] = list[i];
			}
			Income_Management* xoa = list;
			list = NewList;
			delete[] xoa;
		}
	Income_Management x;
	if (wcount == 0) {
		cout << "No wallets available!" << endl;
		return list;
	}
	else {
		cout << "--- CHOOSE WALLETS: ---" << endl;
		for (int i = 0; i < wcount; i++) {
			cout << i + 1 << ". " << wlist[i].Name << endl;
		}
		int wchoice;
		cout << "select wallet number: " << endl;
		cin >> wchoice;
		if (wchoice < 1 || wchoice > wcount) {
			cout << "Invalid selection!" << endl;
			return list;
		}
		else {
			x.WalletID = wlist[wchoice - 1].ID;
		}
		if (scount == 0) {
			cout << "ERROR: No income sources available" << endl;
			return list;
		}

		cout << "--- SELECT INCOME SOURCE ---" << endl;
		for (int i = 0; i < scount; i++) {
			cout << "[" << i + 1 << "] " << slist[i].Name << endl;
		}
		int sChoice;
		cout << "Select source number: ";
		cin >> sChoice;
		if (sChoice < 1 || sChoice > scount) {
			cout << "Invalid selection! Operation cancelled." << endl;
			return list;
		}
		x.SourceID = slist[sChoice - 1].ID;
		cin >> x;
		list[n++] = x;
		wlist[wchoice - 1].balance += x.amount;
		cout << "Income added & Wallet updated!" << endl;
	}
	return list;
}
Income_Management* Income_Management::remove(Income_Management*& list, int& n, Wallets* wlist, int wcount) {
	if (n == 0) {
		cout << "List is empty!" << endl;
		return list;
	}
	cout << "--- DELETE INCOME TRANSACTION ---" << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". Date: " << list[i].Date
			<< " | Amount: " << (long long)list[i].amount
			<< " | Desc: " << list[i].Description << endl;
	}
	int choice;
	cout << "Enter the number you want to delete: ";
	cin >> choice;
	if (choice < 1 || choice > n) {
		cout << "Invalid selection!" << endl;
		return list;
	}
	int index = choice - 1;
	string targetWalletID = list[index].WalletID;
	bool walletFound = false;
	for (int j = 0; j < wcount; j++) {
		if (wlist[j].ID == targetWalletID) {
			wlist[j].balance -= list[index].amount;
			walletFound = true;
			cout << "Wallet balance updated"<< endl;
			break;
		}
	}
	if (!walletFound) {
		cout << "Warning: The wallet linked to this transaction no longer exists" << endl;
	}
	for (int i = index; i < n - 1; i++) {
		list[i] = list[i + 1];
	}
	n--;
	cout << "Transaction deleted successfully!" << endl;
	return list;
}