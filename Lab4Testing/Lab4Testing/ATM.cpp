#include "pch.h"
#include "BankAccount.h"
#include "ATM.h"

using namespace std;

ATM::ATM(int AN, string NM, int bal)
	:ptr(new BankAccount(AN,NM,bal))
{

}

ATM::ATM()
	: ptr(new BankAccount())
{

}

double ATM::Deposit(double d, int c) {
	return ptr->Deposit(d, c);
}

double ATM::Withdrawal(double w, int c) {
	return ptr->Withdrawal(w, c);
}

void ATM::displayBalance() {
	ptr->displayBalance();
}

int ATM::getAN() {
	return ptr->getAN();
}