#include <Statistics.h>
#include <sstream>
#include <ctime>
using namespace std;

namespace Statistics {
    time_t parseDate(const string &ddmmyyyy) {
        if (ddmmyyyy.empty()) return (time_t)0;
        int d = 0, m = 0, y = 0;
        char s1 = 0, s2 = 0;
        istringstream iss(ddmmyyyy);
        iss >> d >> s1 >> m >> s2 >> y;
        if (!iss || s1 != '/' || s2 != '/') return (time_t)0;
        tm tmv{};
        tmv.tm_mday = d;
        tmv.tm_mon  = m - 1;
        tmv.tm_year = y - 1900;
        tmv.tm_hour = 0; tmv.tm_min = 0; tmv.tm_sec = 0;
        tmv.tm_isdst = -1;
        return mktime(&tmv);
    }

    static time_t recToTime(const string &dateStr) {
        return parseDate(dateStr);
    }

    double totalIncomeBetween(Income_Management* incomes, int incCount, time_t from, time_t to, const string& walletID) {
        if (!incomes || incCount <= 0) return 0.0;
        if (from > to) return 0.0;
        double sum = 0.0;
        for (int i = 0; i < incCount; ++i) {
            time_t t = recToTime(incomes[i].Date);
            if (t == 0) continue;
            if (t >= from && t <= to) {
                if (walletID.empty() || incomes[i].WalletID == walletID) sum += incomes[i].amount;
            }
        }
        return sum;
    }

    double totalExpenseBetween(Expense_Management* expenses, int expCount, time_t from, time_t to, const string& walletID) {
        if (!expenses || expCount <= 0) return 0.0;
        if (from > to) return 0.0;
        double sum = 0.0;
        for (int i = 0; i < expCount; ++i) {
            time_t t = recToTime(expenses[i].Date);
            if (t == 0) continue;
            if (t >= from && t <= to) {
                if (walletID.empty() || expenses[i].WalletID == walletID) sum += expenses[i].amount;
            }
        }
        return sum;
    }

    static int findStatIndex(StatPair* arr, int count, const string& id) {
        for (int i = 0; i < count; ++i) {
            if (arr[i].ID == id) return i;
        }
        return -1;
    }

    StatPair* expenseByCategory(Expense_Management* expenses, int expCount, time_t from, time_t to, int &outCount) {
        outCount = 0;
        StatPair* result = nullptr;
        if (!expenses || expCount <= 0) return result;
        if (from > to) return result;

        for (int i = 0; i < expCount; ++i) {
            time_t t = recToTime(expenses[i].Date);
            if (t == 0) continue;
            if (t < from || t > to) continue;

            const string &cid = expenses[i].CategoryID;
            int idx = findStatIndex(result, outCount, cid);
            if (idx >= 0) {
                result[idx].total += expenses[i].amount;
            } else {
                StatPair* tmp = new StatPair[outCount + 1];
                for (int j = 0; j < outCount; ++j) tmp[j] = result[j];
                tmp[outCount].ID = cid;
                tmp[outCount].total = expenses[i].amount;
                delete[] result;
                result = tmp;
                outCount++;
            }
        }
        return result;
    }

    StatPair* incomeBySource(Income_Management* incomes, int incCount, time_t from, time_t to, int &outCount) {
        outCount = 0;
        StatPair* result = nullptr;
        if (!incomes || incCount <= 0) return result;
        if (from > to) return result;

        for (int i = 0; i < incCount; ++i) {
            time_t t = recToTime(incomes[i].Date);
            if (t == 0) continue;
            if (t < from || t > to) continue;

            const string &sid = incomes[i].SourceID;
            int idx = findStatIndex(result, outCount, sid);
            if (idx >= 0) {
                result[idx].total += incomes[i].amount;
            } else {
                StatPair* tmp = new StatPair[outCount + 1];
                for (int j = 0; j < outCount; ++j) tmp[j] = result[j];
                tmp[outCount].ID = sid;
                tmp[outCount].total = incomes[i].amount;
                delete[] result;
                result = tmp;
                outCount++;
            }
        }
        return result;
    }

    MonthlyNet monthlyNetForYear(Income_Management* incomes, int incCount, Expense_Management* expenses, int expCount, int year) {
        MonthlyNet net;
        for (int i = 0; i < 12; ++i) net.month[i] = 0.0;

        if (incomes && incCount > 0) {
            for (int i = 0; i < incCount; ++i) {
                time_t t = recToTime(incomes[i].Date);
                if (t == 0) continue;
                tm *pt = localtime(&t);
                int y = pt->tm_year + 1900;
                int mo = pt->tm_mon; // 0..11
                if (y == year && mo >=0 && mo < 12) net.month[mo] += incomes[i].amount;
            }
        }

        if (expenses && expCount > 0) {
            for (int i = 0; i < expCount; ++i) {
                time_t t = recToTime(expenses[i].Date);
                if (t == 0) continue;
                tm *pt = localtime(&t);
                int y = pt->tm_year + 1900;
                int mo = pt->tm_mon;
                if (y == year && mo >=0 && mo < 12) net.month[mo] -= expenses[i].amount;
            }
        }

        return net;
    }

    StatPair* walletSummary(Income_Management* incomes, int incCount, Expense_Management* expenses, int expCount, time_t from, time_t to, int &outCount) {
        outCount = 0;
        StatPair* result = nullptr;

        if (from > to) return result;

        if (incomes && incCount > 0) {
            for (int i = 0; i < incCount; ++i) {
                time_t t = recToTime(incomes[i].Date);
                if (t == 0) continue;
                if (t < from || t > to) continue;

                const string &wid = incomes[i].WalletID;
                int idx = findStatIndex(result, outCount, wid);
                if (idx >= 0) result[idx].total += incomes[i].amount;
                else {
                    StatPair* tmp = new StatPair[outCount + 1];
                    for (int j = 0; j < outCount; ++j) tmp[j] = result[j];
                    tmp[outCount].ID = wid;
                    tmp[outCount].total = incomes[i].amount;
                    delete[] result;
                    result = tmp;
                    outCount++;
                }
            }
        }

        if (expenses && expCount > 0) {
            for (int i = 0; i < expCount; ++i) {
                time_t t = recToTime(expenses[i].Date);
                if (t == 0) continue;
                if (t < from || t > to) continue;

                const string &wid = expenses[i].WalletID;
                int idx = findStatIndex(result, outCount, wid);
                if (idx >= 0) result[idx].total -= expenses[i].amount;
                else {
                    StatPair* tmp = new StatPair[outCount + 1];
                    for (int j = 0; j < outCount; ++j) tmp[j] = result[j];
                    tmp[outCount].ID = wid;
                    tmp[outCount].total = -expenses[i].amount;
                    delete[] result;
                    result = tmp;
                    outCount++;
                }
            }
        }
        return result;
    }
}
