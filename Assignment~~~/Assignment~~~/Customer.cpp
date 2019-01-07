#include "Customer.h"

using namespace std;

Customer::Customer(string name, string id, string acc_no)
	:ptr(new Student(name,id,acc_no)){}

void Customer::GetName() {
	ptr->GetName();
}

void Customer::GetID() {
	ptr->GetID();
}

int Customer::Owned() {
	return ptr->Owned();
}

string Customer::GetOwnedRoom() {
	return ptr->GetOwnedRoom();
}


Accomodation Customer::Reserve(Accomodation name, int block, int floor, int room, int period, int cond) {
	return ptr->Reserve(name, block, floor, room,period,cond);
}

Accomodation Customer::Cancel_Reserve(Accomodation name, int block, int floor, int room) {
	return ptr->Cancel_Reserve(name, block, floor, room);
}

void Customer::GetRent() {
	ptr->GetRent();
}