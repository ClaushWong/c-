#include "Ticket.h"

Ticket::Ticket(int id, int types, int amount, int price)
	:ID(id), Types(types), Amount(amount), Prices(price)
{}

int Ticket::getID() {
	return ID;
}

int Ticket::getTypes() {
	return Types;
}

int Ticket::getAmount() {
	return Amount;
}

int Ticket::getPrices() {
	return Prices;
}