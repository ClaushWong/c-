#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
class BankAccount
{
	public:
		BankAccount(int AN, std::string NM, int bal = 0);
		BankAccount();
		double Deposit(double d, int c);
		double Withdrawal(double w, int c);
		void displayBalance();
		int getAN();

	private:
		int AccNum;
		std::string name;
		double Balance;

		double Calculate(double d, int c);
};

#endif