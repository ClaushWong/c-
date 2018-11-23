#include "pch.h"
#include "BankAccount.h"
#include <iostream>

using namespace std;

BankAccount::BankAccount(int AN, string NM , int bal)
{
	AccNum = AN;
	name = NM;
	Balance = bal;
}

BankAccount::BankAccount() {
	AccNum = 0;
	name = "";
	Balance = 0;
}

double BankAccount::Deposit(double d, int c) {
	Balance = Calculate(d, c);
	return Balance;
}

double BankAccount::Withdrawal(double w, int c) {
	Balance = Calculate(w, c);
	return Balance;
}

double BankAccount::Calculate(double d, int c) {
	switch (c) {
		case 1:
			return Balance + d;
			break;
		case 2:
			if (Balance - d > 10) {
				return Balance - d;
			}
			else
				cout << "No can do because balance in your account is too low." << endl;
				return Balance;
			break;
		default :
			return Balance;
	}
}

void BankAccount::displayBalance() {
	cout << "Balance : RM" << Balance;
}

int BankAccount::getAN() {
	return AccNum;
}