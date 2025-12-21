#include "Savedata.h"
typedef long long ll;
void saveWalletData(string& filename, Wallets* list, int n) {
	ofstream out(filename, ios::binary);
	if (!out) {
		cerr << "Error opening file for saving" << endl;
	}
	else {
		out.write((char*)(&n), sizeof(n));
		for (int i = 0; i < n; i++) {
			ll IDlength = list[i].ID.size();
			out.write((char*) (& IDlength), sizeof(IDlength));
			out.write(list[i].ID.c_str(), IDlength);
			ll Namelength = list[i].Name.size();
			out.write((char*)(&Namelength), sizeof(Namelength));
			out.write(list[i].Name.c_str(), Namelength);
			out.write((char*)(&list[i].balance), sizeof(list[i].balance));
		}
	}
	out.close();
}
void saveExpense_categories(string& filename, Expense_Categories* list, int n) {
	ofstream out(filename, ios::binary);
	if (!out) {
		cerr << "Error opening file for saving" << endl;
	}
	else {
		out.write((char*)(&n), sizeof(n));
		for (int i = 0; i < n; i++) {
			ll IDlength = list[i].ID.size();
			out.write((char*)(&IDlength), sizeof(IDlength));
			out.write(list[i].ID.c_str(), IDlength);
			ll Namelength = list[i].Name.size();
			out.write((char*)(&Namelength),sizeof(Namelength));
			out.write(list[i].Name.c_str(), Namelength);
		}
	}
	out.close();
}
void saveIncomeSource(string& filename, Income_Sources* list, int n) {
	ofstream out(filename, ios::binary);
	if (!out) {
		cerr << "Error opening file for saving" << endl;
	}
	else {
		out.write((char*)(&n), sizeof(n));
		for (int i = 0; i < n; i++) {
			ll IDlength = list[i].ID.size();
			out.write((char*)(&IDlength), sizeof(IDlength));
			out.write(list[i].ID.c_str(), IDlength);
			ll Namelength = list[i].Name.size();
			out.write((char*)(&Namelength), sizeof(Namelength));
			out.write(list[i].Name.c_str(), Namelength);
		}
		out.close();
	}
}
void saveIncomeData(string& filename, Income_Management* list, int n) {
	ofstream out(filename, ios::binary);
	if (!out) {
		cerr << "Error opening file for saving" << endl;
	}
	out.write((char*)(&n), sizeof(n));
	for (int i = 0; i < n; i++) {
		ll dateLength = list[i].Date.size();
		out.write((char*)(&dateLength), sizeof(dateLength));
		out.write(list[i].Date.c_str(), dateLength);
		ll sourceIDLength = list[i].SourceID.size();
		out.write((char*)(&sourceIDLength), sizeof(sourceIDLength));
		out.write(list[i].SourceID.c_str(), sourceIDLength);
		out.write((char*)(&list[i].amount), sizeof(list[i].amount));
		ll walletIDLength = list[i].WalletID.size();
		out.write((char*)(&walletIDLength), sizeof(walletIDLength));
		out.write(list[i].WalletID.c_str(), walletIDLength);
		ll descriptionLength = list[i].Description.size();
		out.write((char*)(&descriptionLength), sizeof(descriptionLength));
		out.write(list[i].Description.c_str(), descriptionLength);
	}
	out.close();
}
void saveExpenseData(string& filename, Expense_Management* list, int n) {
	ofstream out(filename, ios::binary);
	if (!out) {
		cerr << "Error opening file for saving" << endl;
	}
	out.write((char*)(&n), sizeof(n));
	for (int i = 0; i < n; i++) {
		ll dateLength = list[i].Date.size();
		out.write((char*)(&dateLength), sizeof(dateLength));
		out.write(list[i].Date.c_str(), dateLength);
		ll CategoryIDlength = list[i].CategoryID.size();
		out.write((char*)(&CategoryIDlength), sizeof(CategoryIDlength));
		out.write(list[i].CategoryID.c_str(), CategoryIDlength);
		out.write(reinterpret_cast<char*>(&list[i].amount), sizeof(list[i].amount));
		ll walletIDLength = list[i].WalletID.size();
		out.write(reinterpret_cast<char*>(&walletIDLength), sizeof(walletIDLength));
		out.write(list[i].WalletID.c_str(), walletIDLength);
		ll descriptionLength = list[i].Description.size();
		out.write((char*)(&descriptionLength), sizeof(descriptionLength));
		out.write(list[i].Description.c_str(), descriptionLength);
	}
	out.close();
}
void saveRecurringData(string&filename,RecurringManager& rm) {
	ofstream out(filename, ios::binary);
	if (!out) {
		cerr << "Error opening file for saving" << endl;
	}
	out.write((char*)(&rm.n), sizeof(rm.n));
	for (int i = 0; i < rm.n; i++) {
		ll IDlength = rm.list[i].ID.size();
		out.write((char*)(&IDlength), sizeof(IDlength));
		out.write(rm.list[i].ID.c_str(), IDlength);
		out.write((char*)(&rm.list[i].isIncome), sizeof(rm.list[i].isIncome));
		ll walletIDLength = rm.list[i].WalletID.size();
		out.write((char*)(&walletIDLength), sizeof(walletIDLength));
		out.write(rm.list[i].WalletID.c_str(), walletIDLength);
		ll categoryOrSourceIDLength = rm.list[i].CategoryOrSourceID.size();
		out.write((char*)(&categoryOrSourceIDLength), sizeof(categoryOrSourceIDLength));
		out.write(rm.list[i].CategoryOrSourceID.c_str(), categoryOrSourceIDLength);
		out.write((char*)(&rm.list[i].amount), sizeof(rm.list[i].amount));
		ll descriptionLength = rm.list[i].Description.size();
		out.write((char*)(&descriptionLength), sizeof(descriptionLength));
		out.write(rm.list[i].Description.c_str(), descriptionLength);
		ll startDateLength = rm.list[i].startDate.size();
		out.write((char*)(&startDateLength), sizeof(startDateLength));
		out.write(rm.list[i].startDate.c_str(), startDateLength);
		ll endDateLength = rm.list[i].endDate.size();
		out.write((char*)(&endDateLength), sizeof(endDateLength));
		out.write(rm.list[i].endDate.c_str(), endDateLength);
		out.write((char*)(&rm.list[i].nextDate), sizeof(rm.list[i].nextDate));
		out.write((char*)(&rm.list[i].freq.type), sizeof(rm.list[i].freq.type));
		out.write((char*)(&rm.list[i].freq.interval), sizeof(rm.list[i].freq.interval));
		out.write((char*)(&rm.list[i].occurrences), sizeof(rm.list[i].occurrences));
	}
	out.close();
}