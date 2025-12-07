#include "Expense.h"
#include <iostream>
#include <string>

using namespace std;

istream& operator>>(istream& in, Expense_Management& a) {
    cout << "ADD EXPENSE TRANSACTION" << endl;
    while (cin.peek() == '\n') cin.ignore();
    cout << "Enter Date (dd/mm/yyyy): ";
    getline(in, a.Date);
    cout << "Enter amount: ";
    in >> a.amount;
    while (cin.peek() == '\n') cin.ignore();
    cout << "Enter description: ";
    getline(in, a.Description);
    return in;
}

Expense_Management* Expense_Management::add(
    Expense_Management*& list,
    int& n,
    int& size,
    Wallets* wlist,
    int wcount,
    Expense_Categories* clist,
    int ccount
) {

    if (n == size) {
        if (n == 0) size = 1;
        else size = 2 * n;
        Expense_Management* NewList = new Expense_Management[size];
        for (int i = 0; i < n; ++i) NewList[i] = list[i];
        Expense_Management* old = list;
        list = NewList;
        delete[] old;
    }

    Expense_Management x;

    if (wcount == 0) {
        cout << "No wallets available. Please create a wallet first.\n";
        return list;
    }

    cout << "\n--- CHOOSE WALLET ---\n";
    for (int i = 0; i < wcount; ++i) {
        cout << (i + 1) << ". " << wlist[i].Name << " (Balance: " << wlist[i].balance << ")\n";
    }
    cout << "Select wallet number (or 0 to cancel): ";
    int wchoice;
    cin >> wchoice;
    if (wchoice == 0) {
        cout << "Cancelled.\n";
        return list;
    }
    if (wchoice < 1 || wchoice > wcount) {
        cout << "Invalid wallet selection. Operation cancelled.\n";
        return list;
    }

    x.WalletID = wlist[wchoice - 1].ID;

    if (ccount == 0) {
        cout << "No expense categories available. Please add categories first.\n";
        return list;
    }

    cout << "\n--- SELECT EXPENSE CATEGORY ---\n";
    for (int i = 0; i < ccount; ++i) {
        cout << (i + 1) << ". " << clist[i].Name << "\n";
    }
    cout << "Select category number (or 0 to cancel): ";
    int cchoice;
    cin >> cchoice;
    if (cchoice == 0) {
        cout << "Cancelled.\n";
        return list;
    }
    if (cchoice < 1 || cchoice > ccount) {
        cout << "Invalid category selection. Operation cancelled.\n";
        return list;
    }
    x.CategoryID = clist[cchoice - 1].ID;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cin >> x;

    list[n++] = x;

    bool found = false;
    for (int j = 0; j < wcount; ++j) {
        if (wlist[j].ID == x.WalletID) {
            wlist[j].balance -= x.amount;
            found = true;
            cout << "Expense added. Wallet \"" << wlist[j].Name << "\" new balance: " << wlist[j].balance << "\n";
            break;
        }
    }
    if (!found) {
        cout << "Warning: wallet for this transaction not found (ID=" << x.WalletID << ").\n";
    }

    return list;
}

Expense_Management* Expense_Management::remove(
    Expense_Management*& list,
    int& n,
    Wallets* wlist,
    int wcount
) {
    if (n == 0) {
        cout << "Expense list is empty.\n";
        return list;
    }

    cout << "\n--- DELETE EXPENSE TRANSACTION ---\n";
    for (int i = 0; i < n; ++i) {
        cout << (i + 1) << ". Date: " << list[i].Date
             << " | Amount: " << list[i].amount
             << " | CategoryID: " << list[i].CategoryID
             << " | Description: " << list[i].Description << "\n";
    }

    cout << "Enter the number you want to delete (or 0 to cancel): ";
    int choice;
    cin >> choice;
    if (choice == 0) {
        cout << "Cancelled.\n";
        return list;
    }
    if (choice < 1 || choice > n) {
        cout << "Invalid selection. Operation cancelled.\n";
        return list;
    }

    int index = choice - 1;
    string targetWalletID = list[index].WalletID;

    bool walletFound = false;
    for (int j = 0; j < wcount; ++j) {
        if (wlist[j].ID == targetWalletID) {
            wlist[j].balance += list[index].amount;
            walletFound = true;
            cout << "Wallet \"" << wlist[j].Name << "\" balance rolled back to: " << wlist[j].balance << "\n";
            break;
        }
    }
    if (!walletFound) {
        cout << "Warning: linked wallet not found. Balance cannot be rolled back.\n";
    }

    for (int i = index; i < n - 1; ++i) list[i] = list[i + 1];
    --n;

    cout << "Transaction deleted successfully.\n";
    return list;
}
