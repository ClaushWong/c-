#include "Customer.h"

using namespace std;

Customer::Customer(string first, string last, string ID, string dob)
	:firstName(first), lastName(last), id(ID), date_of_birth(dob)
{}

vector<Ticket> Customer::TicketPurchase() {
	static int id = 1;
	int select = 0;
	int howmuch = 0;

	cout << endl;

	while (select < 1 || select > 3) {
		cout << "Which types of data you want?\n1. Premium (RM15 per)\n2. Standard (RM10 per)\n3. Special (RM5 per)\n";
		cout << "Selection : ";
		cin >> select;
	}

	cout << endl;

	while (howmuch < 1) {
		cout << "How many ticket do you want?\n";
		cout << "Amount : ";
		cin >> howmuch;
	}

	int price = CalculatePrices(select,howmuch);
    //subTotal = price;

	Ticket proto(id,select, howmuch, price);
	tickets.push_back(proto);

	id++;
	return tickets;
}

vector<Ticket> Customer::TicketCancel() {
	int id;

	int confirm;
	TicketDisplay(0);

	cout << endl;

	if (!tickets.empty()){
		cout << "Insert ticket ID you wish to cancel\n";
		cout << "Ticket ID : ";
		cin >> id;

		//tickets.erase(tickets.begin() + id-1);
		for(int x = 0; x < (int)tickets.size(); x++){
            if(tickets[x].getID() == id) {
                confirm = x;
                break;
            }
		}
		tickets.erase(tickets.begin() + confirm);
		cout << "Canceled.\n";
	}

	else {
		cout << "No ticket is being purchased yet.\n";
	}
	return tickets;
}

string Customer::getFirst() {
	return firstName;
}

string Customer::getLast() {
	return lastName;
}

string Customer::getId() {
	return id;
}

string Customer::getDob() {
	return date_of_birth;
}

void Customer::TicketDisplay(int cond) {
	if (cond == 1){
		cout << "User First Name    : " << getFirst() << endl;
		cout << "User Last  Name    : " << getLast() << endl;
		cout << "User ID            : " << getId() << endl;
		cout << "User Date Of Birth : " << getDob() << endl;

		cout << endl;
	}

	if (!tickets.empty()){
		for (int i = 0; i < (int)tickets.size(); i++) {
			cout << "Ticket ID     : " << tickets[i].getID() << endl;
			cout << "Ticket Types  : ";
			switch (tickets[i].getTypes()) {
				case 1:
					cout << "Premium" << endl;
					break;
				case 2:
					cout << "Standard" << endl;
					break;
				case 3:
					cout << "Special" << endl;
					break;
			}
			cout << "Ticket Amount : " << tickets[i].getAmount() << endl;
			cout << "Ticket Prices : RM" << tickets[i].getPrices() << endl;
			//cout << "Total Ticket(s) Prices: RM" << TotalPrice()<< endl;
			cout << endl;
		}
		cout << endl;
	}
	else {
		cout << "No ticket" << endl;
	}
}

int Customer::CalculatePrices(int typ, int amo) {
	switch (typ) {
		case 1:
			return 15 * amo;
			break;
		case 2:
			return 10 * amo;
			break;
		case 3:
			return 5 * amo;
			break;
	}
	return 0;
}

int Customer::TotalPrice(){
        int sum_of_elems = 0;
        for (int i = 0; i < (int) tickets.size(); i++) {
            sum_of_elems += tickets[i].getPrices();
        }
    return sum_of_elems;
};


//int Customer::TotalPrice(){}
