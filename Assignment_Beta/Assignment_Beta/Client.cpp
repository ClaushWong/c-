#include "Client.h"

using namespace std;

Client::Client(string first, string last, string id, string dob)
	:ptr(new Customer(first,last,id,dob))
{}

vector<Ticket> Client::TicketPurchase() {
	return ptr->TicketPurchase();
}

vector<Ticket> Client::TicketCancel() {
	return ptr->TicketCancel();
}

void Client::TicketDisplay(int cond) {
	ptr->TicketDisplay(cond);
}