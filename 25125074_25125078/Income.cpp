#include "Income.h"
istream& operator>>(istream& in, Income_Management& a) {
	cout << "Add new income transaction" << endl;
	cout << "Enter Date(dd/mm/yyyy): "<< endl;
	in >> a.Date;
	cout << "Enter amount: " << endl;
	in >> a.amount;
	cout << "Enter description: ";
	while (cin.peek() == '\n') cin.ignore();
	getline(cin, a.Description);
	return in;
}
Income_Management* Income_Management::add(Income_Management*& list, int& n, int& size, Wallets* wlist, int wcount, Income_Sources* slist, int scount) {
	if (n == size) {
		if (n == 0) size = n + 1;
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
}