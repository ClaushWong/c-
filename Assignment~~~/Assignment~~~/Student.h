#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

#include "Accomodation.h"

class Student
{
	std::string student_name;
	std::string student_id;
	std::string account_no;
	std::string owned_room = "";
	int rent_period;
	int total_price;

	void CalculateTotalPrice(Accomodation name, int block, int floor, int room, int cond);

	public:
		Student(std::string name,std::string id, std::string acc_no);
		void GetName();
		void GetID();
		std::string GetOwnedRoom();
		int Owned();
		void GetRent();
		Accomodation Reserve(Accomodation name ,int block,int floor, int room, int period, int cond);
		Accomodation Cancel_Reserve(Accomodation name, int block, int floor, int room);
};

#endif