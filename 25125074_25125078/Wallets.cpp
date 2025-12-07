#include "Wallets.h"
#include <algorithm>
#include <iostream>
#include <string>
#include "Utils.h"

using namespace std;

Wallets* Wallets::them(Wallets* A, int& n, int& size) {
	if (n == size) {
		if (size == 0) size = size + 1;
		else size = size * 2;
		Wallets* New_wallet_list = new Wallets[size];
		for (int i = 0; i < n; i++) {
			New_wallet_list[i] = A[i];
		}
		Wallets* xoa = A;
		A = New_wallet_list;
		delete[] xoa;
	}
	Wallets a;
	cout << "Enter the wallet name: " << endl;
	while (cin.peek() == '\n') cin.ignore();
	getline(cin, a.Name);
	a.ID = generateUUID();//can use getUniqueId to generate random numbers without duplicates but it is slow
	A[n] = a;
	n++;
	return A;
}

Wallets* Wallets::xoa(Wallets* A, int& n) {
	if (n == 0) {
		cout << "There is nothing to delete" << endl;
		return A;
	}
	else {
		cout << "Delete Wallet" << endl;
		for (int i = 0; i < n; i++) {
			cout << i + 1 << ". " << A[i].Name << endl;
		}
		int choice;
		cout << "Enter the number you want to delete: " << endl;
		choice = inputInt();
		if (choice <= 0 || choice > n) cout << "Invalid index" << endl;
		else {
			for (int i = choice - 1; i < n - 1; i++) {
				A[i] = A[i + 1];
			}
			n--;
			cout << "Deleted successfully!" << endl;
		}
		return A;
	}
}

Wallets* Wallets::edit(Wallets* A, int& n) {
	if (n == 0) {
		cout << "There is nothing to edit" << endl;
		return A;
	}
	else {
		cout << "Edit Wallet" << endl;
		for (int i = 0; i < n; i++) {
			cout << i + 1 << ". " << A[i].Name << endl;
		}
		int choice;
		cout << "Enter the number you want to edit: " << endl;
		choice = inputInt();
		if (choice <= 0 || choice > n) cout << "Invalid index" << endl;
		else {
			cout << "Enter the new name for Wallet: " << endl;
			string a;
			while (cin.peek() == '\n') cin.ignore();
			getline(cin, a);
			A[choice - 1].Name = a;
			cout << "Edit successfully!" << endl;
		}
		return A;
	}
}

Wallets* Wallets::move(Wallets* A, int& n) {
	if (n <= 1) {
		cout << "Cannot move (Not enough elements)" << endl;
		return A;
	}
	else {
		cout << "Move Wallets" << endl;
		while (true) {
			for (int i = 0; i < n; i++) {
				cout << i + 1 << ". " << A[i].Name << endl;
			}
			int choice;
			cout << "Choose the number you want to move up or down" << endl;
			cout << "Enter 0 to stop" << endl;
			choice = inputInt();
			if (choice < 0 || choice > n) cout << "Invalid index" << endl;
			else if (choice == 1) {
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
				cout << "Enter 1 to move up and Enter 2 to move down: ";
				int dir;
				dir= inputInt();
				if (dir == 1) swap(A[choice - 1], A[choice - 2]);
				else if (dir == 2) swap(A[choice - 1], A[choice]);
				else cout << "Invalid movement" << endl;
			}
		}
	}
	return A;
}