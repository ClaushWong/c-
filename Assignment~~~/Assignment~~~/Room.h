#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room
{
	public:
		std::string room_name;
		int status = 0;
		int price_per_sem;  // Cendi & Amanah : $50 [USD]  , Ilmu & Murni : $30 [USD]
		int price_per_year; // Cendi & Amanah : $45 [USD]  , Ilmu & Murni : $27 [USD]

		Room(std::string, int, int);
};

#endif