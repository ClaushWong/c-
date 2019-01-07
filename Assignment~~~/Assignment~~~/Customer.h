#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Student.h"

class Customer
{
	Student *ptr;

	public:
		Customer(std::string name, std::string id, std::string acc_no);
		void GetName();
		void GetID();
		std::string GetOwnedRoom();
		int Owned();
		void GetRent();
		Accomodation Reserve(Accomodation name, int block, int floor, int room, int period, int cond);
		Accomodation Cancel_Reserve(Accomodation name, int block, int floor, int room);
};

#endif