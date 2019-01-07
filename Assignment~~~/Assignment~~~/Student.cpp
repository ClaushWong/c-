#include "Student.h"

using namespace std;

Student::Student(string name, string id, string acc_no)
	:student_name(name), student_id(id), account_no(acc_no)
{
	cout << "Welcome " << student_name << endl;
}

void Student::GetName() {
	cout << student_name;
}

void Student::GetID() {
	cout << student_id;
}

int Student::Owned() {
	if (owned_room != "") {
		return 1;
	}
	else {
		return 0;
	}
}

Accomodation Student::Reserve(Accomodation name, int block, int floor, int room, int period, int cond) {
	owned_room = name.layout[block][floor][room].room_name;
	rent_period = period;
	name.layout[block][floor][room].status = 1;

	CalculateTotalPrice(name, block, floor, room, cond);
	cout << "Reserve complete." << endl;
	return name;
}

string Student::GetOwnedRoom() {
	if (Student::Owned() == 0) {
		return "No room is reserved yet";
	}
	else {
		return owned_room;
	}
}

Accomodation Student::Cancel_Reserve(Accomodation name, int block, int floor, int room) {
	owned_room = "";
	name.layout[block][floor][room].status = 0;

	cout << "Cancel Reservation completed." << endl;
	return name;
}

void Student::CalculateTotalPrice(Accomodation name, int block, int floor, int room, int cond) {
	if (cond == 1)
		total_price = name.layout[block][floor][room].price_per_sem * rent_period;
	else if (cond == 2)
		total_price = name.layout[block][floor][room].price_per_year * rent_period;
}

void Student::GetRent() {
	if (Student::Owned() == 0) {
		cout << "None" << endl;
	}
	else {
		cout << total_price << "USD" << endl;
	}
}