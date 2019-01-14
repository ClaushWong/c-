#ifndef TICKET_H
#define TICKET_H
class Ticket
{
	int ID;
	int Types;
	int Amount;
	int Prices;

	public:
		Ticket(int,int,int,int);
		int getID();
		int getTypes();
		int getAmount();
		int getPrices();
};

#endif