#include "Expense_categories.h"
#include <algorithm>
Expense_Categories* Expense_Categories::them(Expense_Categories* A, int &n, int &size) {
	if (n == size) {
		if (size == 0) size = size + 1;
		else size = size * 2;
		Expense_Categories* New_chi_phi = new Expense_Categories[size];
		for (int i = 0; i < n; i++) {
			New_chi_phi[i]=A[i];
		}
		Expense_Categories* xoa = A;
		A = New_chi_phi;
		delete[] xoa;
	}
		Expense_Categories a;
		cout << "Enter the expense name: " << endl;
		while(cin.peek() == '\n') cin.ignore();
		getline(cin, a.Name);
		a.ID =generateUUID();//can use getUniqueId to generate random numbers without duplicates but it is slow
		A[n] = a;
		n++;
		return A;
}
Expense_Categories* Expense_Categories::xoa(Expense_Categories* A, int& n) {
	if (n == 0) {
		cout << "There is nothing to delete" << endl;
		return A;
	}
	else {
		cout << "delete expense categories" << endl;
		for (int i = 0; i < n; i++) {
			cout << i + 1 << ". " << A[i].Name << endl;
		}
		int choice;
		cout << "Enter the number you want to delete" << endl;
		cin >> choice;
		if (choice <= 0 || choice > n) cout << "Invalid index";
		else {
			for (int i = choice - 1; i < n-1; i++) {
				A[i] = A[i + 1];
			}
			n--;
			cout << "Deleted successfully!" << endl;
		}
		return A;
	}
}
Expense_Categories* Expense_Categories::edit(Expense_Categories* A, int& n) {
	if (n == 0) {
		cout << "There is nothing to edit" << endl;
		return A;
	}
	else {
		cout << "Edit expense categories" << endl;
		for (int i = 0; i < n; i++) {
			cout << i + 1 << ". " << A[i].Name << endl;
		}
		int choice;
		cout << "Enter the number you want to edit" << endl;
		cin >> choice;
		if (choice <= 0 || choice > n) cout << "Invalid index";
		else {
			cout << "Edit the name of Expense_Categories: " << endl;
			string a;
			while(cin.peek() == '\n') cin.ignore();
			getline(cin, a);
			A[choice - 1].Name = a;
			cout << "Edit successfully!" << endl;
		}
		return A;
	}
}
Expense_Categories* Expense_Categories::move(Expense_Categories* A, int& n) {
	if (n <=1) {
		cout << "Cannot move" << endl;
		return A;
	}
	else {
		cout << "Move Expense categories" << endl;
		while (true) {
			for (int i = 0; i < n; i++) {
				cout << i + 1 << ". " << A[i].Name << endl;
			}
			int choice;
			cout << "Choose the number you want to move up or down" << endl;
			cout << "Enter 0 to stop" << endl;
			cin >> choice;
			if (choice < 0 || choice > n) cout << "Invalid index";
			else if(choice==1){
				cout << "Move the first element down" << endl;
				swap(A[0], A[1]);
			}
			else if (choice == n) {
				cout << "Move the last element up" << endl;
				swap(A[n - 1], A[n - 2]);
			}
			else if (choice == 0) {
				break;
			}
			else {
				cout << "Enter 1 to move up and Enter 2 to move down";
				int dir;
				cin >> dir;
				if (dir == 1) swap(A[choice - 1], A[choice - 2]);
				else if (dir == 2) swap(A[choice - 1], A[choice]);
				else cout << "Invalid movement";
			}
		}
	}
	return A;
}