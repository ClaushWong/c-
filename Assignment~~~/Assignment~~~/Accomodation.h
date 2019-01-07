#ifndef ACCOMODATION_H
#define ACCOMODATION_H

#include <iostream>
#include <string>
#include <vector>

#include "Room.h"

class Accomodation
{
	int accomodation_id;
	std::string accomodation_name;
	int amount_of_blocks;
	int amount_of_floors;
	int amount_of_rooms;
	int available_room = 0;

	std::vector<Room> room;
	std::vector<std::vector<Room>> floor;
	
	public:
		std::vector<std::vector<std::vector<Room>>> layout;

		Accomodation(int id,std::string name,int blocks, int floors, int rooms);
		void Display();
		int GetBlock();
		int GetFloor();
		int GetRoom();
		int GetPrice(int);
		void GetAvailableRoom(int,int);
};

#endif