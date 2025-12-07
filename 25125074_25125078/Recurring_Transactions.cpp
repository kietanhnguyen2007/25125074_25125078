#include "Recurring_Transactions.h"
#include <iostream>
#include <sstream>
using namespace std;

static time_t parseDate(const string &s) {
    if (s.empty()) return 0;
    int d = 0, m = 0, y = 0;
    char c1 = 0, c2 = 0;
    stringstream ss(s);
    ss >> d >> c1 >> m >> c2 >> y;
    if (!ss || c1 != '/' || c2 != '/') return 0;

    tm tmv{};
    tmv.tm_mday = d;
    tmv.tm_mon  = m - 1;
    tmv.tm_year = y - 1900;
    tmv.tm_hour = 0;
    tmv.tm_min  = 0;
    tmv.tm_sec  = 0;
    tmv.tm_isdst = -1;

    return mktime(&tmv);
}

static string formatDate(time_t t) {
    if (t == 0) return "";

    tm *pt = localtime(&t);

    char buf[16];
    sprintf(buf, "%02d/%02d/%04d", pt->tm_mday, pt->tm_mon + 1, pt->tm_year + 1900);
    return buf;
}

static time_t advanceByFrequency(time_t base, const RecurringFrequency &freq) {
    if (base == 0) return 0;

    tm tmv = *localtime(&base);

    if (freq.type == R_DAILY) {
        return base + (freq.interval * 24 * 60 * 60);
    }
    else if (freq.type == R_WEEKLY) {
        return base + (freq.interval * 7 * 24 * 60 * 60);
    }
    else if (freq.type == R_MONTHLY) {
        tmv.tm_mon += freq.interval;
        return mktime(&tmv);
    }
    else if (freq.type == R_YEARLY) {
        tmv.tm_year += freq.interval;
        return mktime(&tmv);
    }

    return base;
}

static void ensureIncomeCapacity(Income_Management *&arr, int &size, int required) {
    if (size >= required) return;

    int newSize = (size == 0 ? 1 : size * 2);
    while (newSize < required) newSize *= 2;

    Income_Management *tmp = new Income_Management[newSize];
    for (int i = 0; i < size; i++) tmp[i] = arr[i];

    delete[] arr;
    arr = tmp;
    size = newSize;
}

static void ensureExpenseCapacity(Expense_Management *&arr, int &size, int required) {
    if (size >= required) return;

    int newSize = (size == 0 ? 1 : size * 2);
    while (newSize < required) newSize *= 2;

    Expense_Management *tmp = new Expense_Management[newSize];
    for (int i = 0; i < size; i++) tmp[i] = arr[i];

    delete[] arr;
    arr = tmp;
    size = newSize;
}

static void appendIncome(Income_Management *&incomes, int &incN, int &incSize, const RecurringEntry &r, Wallets *wlist, int wcount)
{
    ensureIncomeCapacity(incomes, incSize, incN + 1);
    Income_Management rec;
    rec.Date        = formatDate(r.nextDate);
    rec.SourceID    = r.CategoryOrSourceID;
    rec.amount      = r.amount;
    rec.WalletID    = r.WalletID;
    rec.Description = r.Description;

    incomes[incN++] = rec;

    for (int i = 0; i < wcount; i++) {
        if (wlist[i].ID == r.WalletID) {
            wlist[i].balance += r.amount;
            break;
        }
    }
}

static void appendExpense(
    Expense_Management *&expenses, int &expN, int &expSize,
    const RecurringEntry &r,
    Wallets *wlist, int wcount)
{
    ensureExpenseCapacity(expenses, expSize, expN + 1);

    Expense_Management rec;
    rec.Date        = formatDate(r.nextDate);
    rec.CategoryID  = r.CategoryOrSourceID;
    rec.amount      = r.amount;
    rec.WalletID    = r.WalletID;
    rec.Description = r.Description;

    expenses[expN++] = rec;
    for (int i = 0; i < wcount; i++) {
        if (wlist[i].ID == r.WalletID) {
            wlist[i].balance -= r.amount;
            break;
        }
    }
}

RecurringManager::RecurringManager() {
    list = nullptr;
    n = 0;
    size = 0;
}

RecurringManager::~RecurringManager() {
    delete[] list;
}

void RecurringManager::add(const RecurringEntry &r) {
    if (n == size) {
        size = (size == 0 ? 1 : size * 2);
        RecurringEntry *tmp = new RecurringEntry[size];
        for (int i = 0; i < n; i++) tmp[i] = list[i];
        delete[] list;
        list = tmp;
    }
    list[n++] = r;
}

bool RecurringManager::remove(int idx) {
    if (idx < 0 || idx >= n) return false;

    for (int i = idx; i < n - 1; i++)
        list[i] = list[i + 1];

    n--;
    return true;
}

void RecurringManager::listAll() const {
    if (n == 0) {
        cout << "No recurring entries.\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        const RecurringEntry &r = list[i];

        cout << i + 1 << ". "
             << (r.isIncome ? "Income" : "Expense")
             << " | amount=" << r.amount
             << " | wallet=" << r.WalletID
             << " | reference=" << r.CategoryOrSourceID
             << " | next=" << formatDate(r.nextDate)
             << " | every " << r.freq.interval 
             << (r.freq.type == R_DAILY ? " days"
                 : r.freq.type == R_WEEKLY ? " weeks"
                 : r.freq.type == R_MONTHLY ? " months"
                 : " years")
             << " | remaining=" << r.occurrences
             << "\n";
    }
}

void RecurringManager::processRecurrences(time_t upToDate, Income_Management *&incomes, int &incN, int &incSize,
    Expense_Management *&expenses, int &expN, int &expSize, Wallets *wlist, int wcount,
    Income_Sources *slist, int scount, Expense_Categories *clist, int ccount) {
    if (upToDate == 0 || n == 0) return;
    for (int i = 0; i < n; i++) {
        RecurringEntry &r = list[i];
        if (r.nextDate == 0)
            r.nextDate = parseDate(r.startDate);

        if (r.nextDate == 0) continue; 

        while (r.nextDate <= upToDate && (r.occurrences != 0)) {
            if (!r.endDate.empty()) {
                time_t endT = parseDate(r.endDate);
                if (endT != 0 && r.nextDate > endT)
                    break;
            }
            if (r.isIncome)
                appendIncome(incomes, incN, incSize, r, wlist, wcount);
            else
                appendExpense(expenses, expN, expSize, r, wlist, wcount);
            if (r.occurrences > 0)
                r.occurrences--;
            r.nextDate = advanceByFrequency(r.nextDate, r.freq);

            if (r.nextDate == 0) break;
        }
    }
}
