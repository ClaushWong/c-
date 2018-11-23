#ifndef ATM_H
#define ATM_H

#include <string>

class BankAccount;
class ATM
{
	public:
		ATM(int AN, std::string NM,int bal=0);
		ATM();
		double Deposit(double d, int c);
		double Withdrawal(double w, int c);
		void displayBalance();
		int getAN();

	private:
		BankAccount *ptr;
};

#endif