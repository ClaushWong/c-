#ifndef CLIENT_H
#define CLIENT_H

#include "Customer.h"

class Client
{
	Customer *ptr;
	public:
		Client(std::string, std::string, std::string, std::string);
		std::vector<Ticket> TicketPurchase();
		std::vector<Ticket> TicketCancel();
		void TicketDisplay(int);
};

#endif