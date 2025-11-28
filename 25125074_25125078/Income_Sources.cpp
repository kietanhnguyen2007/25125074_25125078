#include "Income_Sources.h"
#include <algorithm>
#include <iostream>
#include <string>
#include "Utils.h"

using namespace std;

Income_Sources* Income_Sources::them(Income_Sources* A, int& n, int& size) {
	if (n == size) {
		if (size == 0) size = size + 1;
		else size = size * 2;
		Income_Sources* New_nguon_thu = new Income_Sources[size];
		for (int i = 0; i < n; i++) {
			New_nguon_thu[i] = A[i];
		}
		Income_Sources* xoa = A;
		A = New_nguon_thu;
		delete[] xoa;
	}
	Income_Sources a;
	cout << "Enter the income source name: " << endl;
	while (cin.peek() == '\n') cin.ignore();
	getline(cin, a.Name);
	a.ID = generateUUID();
	A[n] = a;
	n++;
	return A;
}

Income_Sources* Income_Sources::xoa(Income_Sources* A, int& n) {
	if (n == 0) {
		cout << "There is nothing to delete" << endl;
		return A;
	}
	else {
		cout << "Delete Income Source" << endl;
		for (int i = 0; i < n; i++) {
			cout << i + 1 << ". " << A[i].Name << endl;
		}
		int choice;
		cout << "Enter the number you want to delete: " << endl;
		cin >> choice;
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

Income_Sources* Income_Sources::edit(Income_Sources* A, int& n) {
	if (n == 0) {
		cout << "There is nothing to edit" << endl;
		return A;
	}
	else {
		cout << "Edit Income Source" << endl;
		for (int i = 0; i < n; i++) {
			cout << i + 1 << ". " << A[i].Name << endl;
		}
		int choice;
		cout << "Enter the number you want to edit: " << endl;
		cin >> choice;
		if (choice <= 0 || choice > n) cout << "Invalid index" << endl;
		else {
			cout << "Enter the new name for Income Source: " << endl;
			string a;
			while (cin.peek() == '\n') cin.ignore();
			getline(cin, a);
			A[choice - 1].Name = a;
			cout << "Edit successfully!" << endl;
		}
		return A;
	}
}

Income_Sources* Income_Sources::move(Income_Sources* A, int& n) {
	if (n <= 1) {
		cout << "Cannot move (Not enough elements)" << endl;
		return A;
	}
	else {
		cout << "Move Income Sources" << endl;
		while (true) {
			for (int i = 0; i < n; i++) {
				cout << i + 1 << ". " << A[i].Name << endl;
			}
			int choice;
			cout << "Choose the number you want to move up or down" << endl;
			cout << "Enter 0 to stop" << endl;
			cin >> choice;
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
				cin >> dir;
				if (dir == 1) swap(A[choice - 1], A[choice - 2]);
				else if (dir == 2) swap(A[choice - 1], A[choice]);
				else cout << "Invalid movement" << endl;
			}
		}
	}
	return A;
}