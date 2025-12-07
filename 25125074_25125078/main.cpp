#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <limits>
#include <ctime>
#include "Wallets.h"
#include "Expense_categories.h"
#include "Income_Sources.h"
#include "Income.h"
#include "Expense.h"
#include "Recurring_Transactions.h"
#include "Statistics.h"
#include "loaddata.h"
#include "Savedata.h"
using namespace std;

void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int askInt(const string &prompt) {
    int x;
    cout << prompt;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid. " << prompt;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return x;
}

string askLine(const string &prompt) {
    cout << prompt;
    string s;
    getline(cin, s);
    return s;
}

void printWallets(Wallets* wlist, int wcount) {
    if (!wlist || wcount == 0) { cout << "No wallets.\n"; return; }
    cout << "=== Wallets ===\n";
    for (int i = 0; i < wcount; ++i) {
        cout << (i+1) << ". " << wlist[i].Name << " | ID: " << wlist[i].ID << " | Balance: " << wlist[i].balance << "\n";
    }
}

void printCategories(Expense_Categories* clist, int ccount) {
    if (!clist || ccount == 0) { cout << "No expense categories.\n"; return; }
    cout << "=== Expense Categories ===\n";
    for (int i = 0; i < ccount; ++i) {
        cout << (i+1) << ". " << clist[i].Name << " | ID: " << clist[i].ID << "\n";
    }
}

void printSources(Income_Sources* slist, int scount) {
    if (!slist || scount == 0) { cout << "No income sources.\n"; return; }
    cout << "=== Income Sources ===\n";
    for (int i = 0; i < scount; ++i) {
        cout << (i+1) << ". " << slist[i].Name << " | ID: " << slist[i].ID << "\n";
    }
}

void printIncomes(Income_Management* incomes, int incCount) {
    if (!incomes || incCount == 0) { cout << "No incomes.\n"; return; }
    cout << "=== Incomes ===\n";
    for (int i = 0; i < incCount; ++i) {
        cout << (i+1) << ". Date: " << incomes[i].Date
             << " | Amount: " << incomes[i].amount
             << " | SourceID: " << incomes[i].SourceID
             << " | WalletID: " << incomes[i].WalletID
             << " | " << incomes[i].Description << "\n";
    }
}

void printExpenses(Expense_Management* expenses, int expCount) {
    if (!expenses || expCount == 0) { cout << "No expenses.\n"; return; }
    cout << "=== Expenses ===\n";
    for (int i = 0; i < expCount; ++i) {
        cout << (i+1) << ". Date: " << expenses[i].Date
             << " | Amount: " << expenses[i].amount
             << " | CategoryID: " << expenses[i].CategoryID
             << " | WalletID: " << expenses[i].WalletID
             << " | " << expenses[i].Description << "\n";
    }
}

void walletsMenu(Wallets*& wlist, int& wcount, int& wsize) {
    while (true) {
        cout << "\n--- Wallets Menu ---\n";
        cout << "1. List wallets\n";
        cout << "2. Add Wallet\n";
        cout << "3. Edit Wallet\n";
        cout << "4. Delete Wallet\n";
        cout << "5. Move Wallet\n";
        cout << "0. Back\n";
        
        int ch = askInt("Choice: ");

        if (ch == 1) {
            printWallets(wlist, wcount);
            pause();
        }
        else if (ch == 2) {
            Wallets temp; 
            wlist = temp.them(wlist, wcount, wsize);
            cout << "Add wallet done.\n";
            pause();
        }
        else if (ch == 3) {
            Wallets temp;
            wlist = temp.edit(wlist, wcount);
            pause();
        }
        else if (ch == 4) {
            Wallets temp;
            wlist = temp.xoa(wlist, wcount);
            pause();
        }
        else if (ch == 5) {
            Wallets temp;
            wlist = temp.move(wlist, wcount);
            pause();
        }
        else if (ch == 0) {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
}

void categoriesMenu(Expense_Categories*& clist, int& ccount, int& csize) {
    while (true) {
        cout << "\n--- Expense Categories Menu ---\n";
        cout << "1. List categories\n";
        cout << "2. Add Category\n";
        cout << "3. Edit Category\n";
        cout << "4. Delete Category\n";
        cout << "5. Move Category\n";
        cout << "0. Back\n";
        
        int ch = askInt("Choice: ");

        if (ch == 1) {
            printCategories(clist, ccount);
            pause();
        }
        else if (ch == 2) {
            Expense_Categories temp;
            clist = temp.them(clist, ccount, csize);
            cout << "Add category done.\n";
            pause();
        }
        else if (ch == 3) {
            Expense_Categories temp;
            clist = temp.edit(clist, ccount);
            pause();
        }
        else if (ch == 4) {
            Expense_Categories temp;
            clist = temp.xoa(clist, ccount);
            pause();
        }
        else if (ch == 5) {
            Expense_Categories temp;
            clist = temp.move(clist, ccount);
            pause();
        }
        else if (ch == 0) break;
        else {
            cout << "Invalid choice.\n";
        }
    }
}

void sourcesMenu(Income_Sources*& slist, int& scount, int& ssize) {
    while (true) {
        cout << "\n--- Income Sources Menu ---\n";
        cout << "1. List sources\n";
        cout << "2. Add Source\n";
        cout << "3. Edit Source\n";
        cout << "4. Delete Source\n";
        cout << "5. Move Source\n";
        cout << "0. Back\n";
        
        int ch = askInt("Choice: ");

        if (ch == 1) {
            printSources(slist, scount);
            pause();
        }
        else if (ch == 2) {
            Income_Sources temp;
            slist = temp.them(slist, scount, ssize);
            cout << "Add source done.\n";
            pause();
        }
        else if (ch == 3) {
            Income_Sources temp;
            slist = temp.edit(slist, scount);
            pause();
        }
        else if (ch == 4) {
            Income_Sources temp;
            slist = temp.xoa(slist, scount);
            pause();
        }
        else if (ch == 5) {
            Income_Sources temp;
            slist = temp.move(slist, scount);
            pause();
        }
        else if (ch == 0) break;
        else {
            cout << "Invalid choice.\n";
        }
    }
}

void incomeMenu(Income_Management*& incomes, int& incCount, int& incSize, Wallets* wlist, int wcount, Income_Sources* slist, int scount) {
    while (true) {
        cout << "\n--- Income Menu ---\n1. List incomes\n2. Add income\n3. Remove income\n0. Back\nChoice: ";
        int ch = askInt("");
        if (ch == 1) { printIncomes(incomes, incCount); pause(); }
        else if (ch == 2) {
            Income_Management tmp;
            incomes = tmp.add(incomes, incCount, incSize, wlist, wcount, slist, scount);
            cout << "Done adding income (if no error shown).\n";
            pause();
        }
        else if (ch == 3) {
            if (incCount == 0) { cout << "No incomes to remove.\n"; pause(); continue; }
            Income_Management tmp;
            incomes = tmp.remove(incomes, incCount, wlist, wcount);
            cout << "Done removal (if selected valid index).\n";
            pause();
        }
        else if (ch == 0) break;
    }
}

void expenseMenu(
    Expense_Management*& expenses, int& expCount, int& expSize,
    Wallets* wlist, int wcount,
    Expense_Categories* clist, int ccount
) {
    while (true) {
        cout << "\n--- Expense Menu ---\n1. List expenses\n2. Add expense\n3. Remove expense\n0. Back\nChoice: ";
        int ch = askInt("");
        if (ch == 1) { printExpenses(expenses, expCount); pause(); }
        else if (ch == 2) {
            Expense_Management tmp;
            expenses = tmp.add(expenses, expCount, expSize, wlist, wcount, clist, ccount);
            cout << "Done adding expense.\n";
            pause();
        }
        else if (ch == 3) {
            if (expCount == 0) { cout << "No expenses to remove.\n"; pause(); continue; }
            Expense_Management tmp;
            expenses = tmp.remove(expenses, expCount, wlist, wcount);
            cout << "Done removal.\n";
            pause();
        }
        else if (ch == 0) break;
    }
}

void recurringMenu(
    RecurringManager& recurring, Income_Management*& incomes, int& incCount, int& incSize,
    Expense_Management*& expenses, int& expCount, int& expSize, Wallets* wlist, int wcount,
    Income_Sources* slist, int scount, Expense_Categories* clist, int ccount) {
    while (true) {
        cout << "\n--- Recurring Menu ---\n1. List recurring\n2. Add recurring (manual)\n3. Remove recurring\n4. Process recurring up to today\n0. Back\nChoice: ";
        int ch = askInt("");
        if (ch == 1) { recurring.listAll(); pause(); }
        else if (ch == 2) {
            RecurringEntry r;
            cout << "Is income? (1 = income, 0 = expense): ";
            r.isIncome = askInt("") != 0;
            cout << "Wallet ID: "; getline(cin, r.WalletID);
            cout << "Category/Source ID: "; getline(cin, r.CategoryOrSourceID);
            cout << "Amount: "; cin >> r.amount; cin.ignore();
            cout << "Description: "; getline(cin, r.Description);
            cout << "Start Date (dd/mm/yyyy): "; getline(cin, r.startDate);
            cout << "End Date (empty for none): "; getline(cin, r.endDate);
            cout << "Interval type (0=day,1=week,2=month,3=year): "; r.freq.type = askInt("");
            cout << "Interval (e.g. 1 = every 1 unit): "; r.freq.interval = askInt("");
            cout << "Occurrences (-1 for infinite): "; r.occurrences = askInt("");
            r.nextDate = 0; 
            recurring.add(r);
            cout << "Recurring entry added.\n";
            pause();
        }
        else if (ch == 3) {
            recurring.listAll();
            cout << "Index to remove (1..n) or 0 to cancel: ";
            int idx = askInt("");
            if (idx > 0) {
                bool ok = recurring.remove(idx - 1);
                cout << (ok ? "Removed.\n" : "Invalid index.\n");
            }
            pause();
        }
        else if (ch == 4) {
            time_t today = time(nullptr);
            recurring.processRecurrences(today, incomes, incCount, incSize,
                                         expenses, expCount, expSize,
                                         wlist, wcount, slist, scount, clist, ccount);
            cout << "Processed up to today: " << ctime(&today);
            pause();
        }
        else if (ch == 0) break;
    }
}

void statisticsMenu(
    Income_Management* incomes, int incCount, Expense_Management* expenses, int expCount,
    Wallets* wlist, int wcount, Expense_Categories* clist, int ccount, Income_Sources* slist, int scount) {
    while (true) {
        cout << "\n--- Statistics Menu ---\n"
             << "1. Total income/expense for a period\n"
             << "2. Expense by category\n"
             << "3. Income by source\n"
             << "4. Monthly net for a year\n"
             << "5. Wallet summary for a period\n"
             << "0. Back\nChoice: ";
        int ch = askInt("");
        if (ch == 1) {
            string fromS = askLine("From (dd/mm/yyyy): ");
            string toS   = askLine("To   (dd/mm/yyyy): ");
            time_t from = Statistics::parseDate(fromS);
            time_t to   = Statistics::parseDate(toS);
            double inc = Statistics::totalIncomeBetween(incomes, incCount, from, to);
            double exp = Statistics::totalExpenseBetween(expenses, expCount, from, to);
            cout << "Income: " << inc << " Expense: " << exp << " Net: " << (inc - exp) << "\n";
            pause();
        }
        else if (ch == 2) {
            string fromS = askLine("From (dd/mm/yyyy): ");
            string toS   = askLine("To   (dd/mm/yyyy): ");
            time_t from = Statistics::parseDate(fromS);
            time_t to   = Statistics::parseDate(toS);
            int count = 0;
            StatPair* arr = Statistics::expenseByCategory(expenses, expCount, from, to, count);
            cout << "Expense by Category:\n";
            for (int i = 0; i < count; ++i) {
                cout << arr[i].ID << " : " << arr[i].total << "\n";
            }
            delete[] arr;
            pause();
        }
        else if (ch == 3) {
            string fromS = askLine("From (dd/mm/yyyy): ");
            string toS   = askLine("To   (dd/mm/yyyy): ");
            time_t from = Statistics::parseDate(fromS);
            time_t to   = Statistics::parseDate(toS);
            int count = 0;
            StatPair* arr = Statistics::incomeBySource(incomes, incCount, from, to, count);
            cout << "Income by Source:\n";
            for (int i = 0; i < count; ++i) cout << arr[i].ID << " : " << arr[i].total << "\n";
            delete[] arr;
            pause();
        }
        else if (ch == 4) {
            int year = askInt("Year (e.g. 2025): ");
            MonthlyNet m = Statistics::monthlyNetForYear(incomes, incCount, expenses, expCount, year);
            cout << "Monthly net for " << year << ":\n";
            for (int mo = 0; mo < 12; ++mo) cout << (mo+1) << ": " << m.month[mo] << "\n";
            pause();
        }
        else if (ch == 5) {
            string fromS = askLine("From (dd/mm/yyyy): ");
            string toS   = askLine("To   (dd/mm/yyyy): ");
            time_t from = Statistics::parseDate(fromS);
            time_t to   = Statistics::parseDate(toS);
            int count = 0;
            StatPair* arr = Statistics::walletSummary(incomes, incCount, expenses, expCount, from, to, count);
            cout << "Wallet summary:\n";
            for (int i = 0; i < count; ++i) {
                cout << arr[i].ID << " : " << arr[i].total << "\n";
            }
            delete[] arr;
            pause();
        }
        else if (ch == 0) break;
    }
}

int main() {
    Wallets* wallets = nullptr; int walletCount = 0, walletSize = 0;
    Expense_Categories* categories = nullptr; int catCount = 0, catSize = 0;
    Income_Sources* sources = nullptr; int srcCount = 0, srcSize = 0;
    Income_Management* incomes = nullptr; int incCount = 0, incSize = 0;
    Expense_Management* expenses = nullptr; int expCount = 0, expSize = 0;
    RecurringManager recurring;

    string WALLET_FILE = "wallets.bin";
    string EXP_CAT_FILE = "expense_categories.bin";
    string SRC_FILE = "income_sources.bin";
    string INCOME_FILE = "income.bin";
    string EXPENSE_FILE = "expense.bin";
    string RECURRING_FILE = "recurring.bin"; 

    loadWalletData(WALLET_FILE, wallets, walletCount, walletSize);
    loadExpense_categories(EXP_CAT_FILE, categories, catCount, catSize);
    loadIncomeSource(SRC_FILE, sources, srcCount, srcSize);
    loadIncomeData(INCOME_FILE, incomes, incCount, incSize);

    while (true) {
        cout << "\n===== DASHBOARD =====\n";
        cout << "1. Wallets\n2. Expense Categories\n3. Income Sources\n4. Income transactions\n5. Expense transactions\n6. Recurring transactions\n7. Statistics\n8. Save all\n0. Exit\nChoice: ";
        int ch = askInt("");
        if (ch == 1) walletsMenu(wallets, walletCount, walletSize);
        else if (ch == 2) categoriesMenu(categories, catCount, catSize);
        else if (ch == 3) sourcesMenu(sources, srcCount, srcSize);
        else if (ch == 4) incomeMenu(incomes, incCount, incSize, wallets, walletCount, sources, srcCount);
        else if (ch == 5) expenseMenu(expenses, expCount, expSize, wallets, walletCount, categories, catCount);
        else if (ch == 6) recurringMenu(recurring, incomes, incCount, incSize, expenses, expCount, expSize, wallets, walletCount, sources, srcCount, categories, catCount);
        else if (ch == 7) statisticsMenu(incomes, incCount, expenses, expCount, wallets, walletCount, categories, catCount, sources, srcCount);
        else if (ch == 8) {
            saveWalletData(WALLET_FILE, wallets, walletCount);
            saveExpense_categories(EXP_CAT_FILE, categories, catCount);
            saveIncomeSource(SRC_FILE, sources, srcCount);
            saveIncomeData(INCOME_FILE, incomes, incCount);
            cout << "Saved.\n";
            pause();
        }
        else if (ch == 0) {
            cout << "Exit. Do you want to save before exit? (1=yes / 0=no): ";
            int s = askInt("");
            if (s == 1) {
                saveWalletData(WALLET_FILE, wallets, walletCount);
                saveExpense_categories(EXP_CAT_FILE, categories, catCount);
                saveIncomeSource(SRC_FILE, sources, srcCount);
                saveIncomeData(INCOME_FILE, incomes, incCount);
                cout << "Saved.\n";
            }
            break;
        } else {
            cout << "Unknown choice.\n";
        }
    }
    delete[] wallets;
    delete[] categories;
    delete[] sources;
    delete[] incomes;
    delete[] expenses;
    return 0;
}
