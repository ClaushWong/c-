#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Ticket.h"
#include <string>
#include <vector>

class Customer
{
	std::string firstName;
	std::string lastName;
	std::string id;
	std::string date_of_birth;
	std::vector<Ticket> tickets;

	int CalculatePrices(int,int);

	public:
		Customer(std::string, std::string, std::string, std::string);
		std::vector<Ticket> TicketPurchase();
		std::vector<Ticket> TicketCancel();
		void TicketDisplay(int);

		std::string getFirst();
		std::string getLast();
		std::string getId();
		std::string getDob();
};

#endif