#include "Accomodation.h"
#include "Room.h"

using namespace std;

Accomodation::Accomodation(int id, string name, int blocks, int floors, int rooms)
	:accomodation_id(id), accomodation_name(name), amount_of_blocks(blocks), amount_of_floors(floors),
	amount_of_rooms(rooms)
{
	string temp_name;
	int pps;
	int ppy;

	for (int i = 0 ; i < amount_of_blocks; i++){
		for (int j = 0; j < amount_of_floors; j++) {
			for (int k = 0; k < amount_of_rooms; k++) {
				switch (accomodation_id) {
					case 1:
						temp_name = "I" + to_string(i + 1) + "-0" + to_string(j+1) + "-0" + to_string(k+1);
						pps = 30;
						ppy = 27;
						break;
					case 2:
						temp_name = "A" + to_string(i + 1) + "-0" + to_string(j + 1) + "-0" + to_string(k + 1);
						pps = 50;
						ppy = 45;
						break;
					case 3:
						if (j != 9)
							temp_name = "C" + to_string(i + 1) + "-0" + to_string(j + 1) + "-0" + to_string(k + 1);
						else
							temp_name = "C" + to_string(i + 1) + "-10-0" + to_string(k + 1);
						pps = 50;
						ppy = 45;
						break;
					case 4:
						if (j != 9)
							temp_name = "M" + to_string(i + 1) + "-0" + to_string(j + 1) + "-0" + to_string(k + 1);
						else
							temp_name = "M" + to_string(i + 1) + "-10-0" + to_string(k + 1);
						pps = 30;
						ppy = 27;
						break;
				}
				
				Room *temp = new Room(temp_name,pps,ppy);
				room.push_back(*temp);
			}
			floor.push_back(room);
			for (int x = 0; x < amount_of_rooms; x++) {
				room.pop_back();
			}
		}
		layout.push_back(floor);
		for (int x = 0; x < amount_of_floors; x++) {
			floor.pop_back();
		}
	}
}

void Accomodation::Display() {
	for (int i = 0; i < amount_of_blocks; i++) {
		for (int j = 0; j < amount_of_floors; j++) {
			for (int k = 0; k < amount_of_rooms; k++) {
				cout << "Name      : " << layout[i][j][k].room_name << endl;
				cout << "Room Type : " << layout[i][j][k].room_name << endl;
				cout << "Status    : ";
				if (layout[i][j][k].status == 0)
					cout << "Unassigned";
				else
					cout << "Assigned";

				cout << endl << endl;
				if (layout[i][j][k].status == 0) {
					available_room++;
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << "Available Room : " << available_room;
	available_room = 0;
}

int Accomodation::GetBlock() {
	return amount_of_blocks;
}

int Accomodation::GetFloor() {
	return amount_of_floors;
}

int Accomodation::GetRoom() {
	return amount_of_rooms;
}

void Accomodation::GetAvailableRoom(int blk, int flr) {
	for (int i = 0; i < amount_of_rooms; i++) {
		if (layout[blk][flr][i].status == 0) {
			cout << i << ". " << layout[blk][flr][i].room_name << endl;
		}
	}
}

int Accomodation::GetPrice(int cond) {
	if (cond == 1) {
		return layout[0][0][0].price_per_sem;
	}
	else if (cond == 2) {
		return layout[0][0][0].price_per_year;
	}
}