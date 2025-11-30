#include "Savedata.h"
typedef long long ll;
void saveWalletData(string& filename, Wallets* list, int n) {
	ofstream out(filename, ios::binary);
	if (!out) {
		cerr << "Error opening file for saving" << endl;
	}
	else {
		out.write(reinterpret_cast<char*>(&n), sizeof(n));
		for (int i = 0; i < n; i++) {
			ll IDlength = list[i].ID.size();
			out.write(reinterpret_cast<char*> (& IDlength), sizeof(IDlength));
			out.write(list[i].ID.c_str(), IDlength);
			ll Namelength = list[i].Name.size();
			out.write(reinterpret_cast<char*>(&Namelength), sizeof(Namelength));
			out.write(list[i].Name.c_str(), Namelength);
			out.write(reinterpret_cast<char*>(&list[i].balance), sizeof(list[i].balance));
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
		out.write(reinterpret_cast<char*>(&n), sizeof(n));
		for (int i = 0; i < n; i++) {
			ll IDlength = list[i].ID.size();
			out.write(reinterpret_cast<char*>(&IDlength), sizeof(IDlength));
			out.write(list[i].ID.c_str(), IDlength);
			ll Namelength = list[i].Name.size();
			out.write(reinterpret_cast<char*>(&Namelength),sizeof(Namelength));
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
		out.write(reinterpret_cast<char*>(&n), sizeof(n));
		for (int i = 0; i < n; i++) {
			ll IDlength = list[i].ID.size();
			out.write(reinterpret_cast<char*>(&IDlength), sizeof(IDlength));
			out.write(list[i].ID.c_str(), IDlength);
			ll Namelength = list[i].Name.size();
			out.write(reinterpret_cast<char*>(&Namelength), sizeof(Namelength));
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
	out.write(reinterpret_cast<char*>(&n), sizeof(n));
	for (int i = 0; i < n; i++) {
		ll dateLength = list[i].Date.size();
		out.write(reinterpret_cast<char*>(&dateLength), sizeof(dateLength));
		out.write(list[i].Date.c_str(), dateLength);
		ll sourceIDLength = list[i].SourceID.size();
		out.write(reinterpret_cast<char*>(&sourceIDLength), sizeof(sourceIDLength));
		out.write(list[i].SourceID.c_str(), sourceIDLength);
		out.write(reinterpret_cast<char*>(&list[i].amount), sizeof(list[i].amount));
		ll walletIDLength = list[i].WalletID.size();
		out.write(reinterpret_cast<char*>(&walletIDLength), sizeof(walletIDLength));
		out.write(list[i].WalletID.c_str(), walletIDLength);
		ll descriptionLength = list[i].Description.size();
		out.write(reinterpret_cast<char*>(&descriptionLength), sizeof(descriptionLength));
		out.write(list[i].Description.c_str(), descriptionLength);
	}
	out.close();
}