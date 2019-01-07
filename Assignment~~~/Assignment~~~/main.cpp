#include "Accomodation.h"
#include "Customer.h"

#include <cstdlib>
#include <Windows.h>
#include <sstream>

using namespace std;

Customer Student_X() {
	string stud_name;
	string stud_id;
	string acc_no;

	cout << "Welcome student, give me your name.\nName : ";
	getline(cin, stud_name);

	cout << endl << "Your Student ID please : ";
	cin >> stud_id;

	cout << endl << "Your account number ( don't worry, wo wouldn't do anything to your account )\nAccount No : ";
	cin >> acc_no;

	Customer temp(stud_name, stud_id, acc_no);
	return temp;
}

int getAccomodationId() {
	int id = 0;
	while (id < 1 || id > 4) {
		cout << "Which accomodation you would like to choose?\n";
		cout << "1. Ilmu" << endl;
		cout << "2. Amanah" << endl;
		cout << "3. Cendekiawan" << endl;
		cout << "4. Murni" << endl;
		cout << "Accomodation : "; cin >> id;
		cout << endl;
	}
	return id;
}

// GET BLOCK NUM , FLOOR NUM , ROOM NUM TO PERFORM CHECKING WHETHER USER INPUT IN RANGE OR NOT
int getParticular(int par) {
	int par_no = -1;
	while (par_no < 0 || par_no > par) {
		cout << "Selection : ";
		cin >> par_no;
	}
	return par_no;
}


int main() {
	// DECLARE WITH FORMAT ( ID , NAME , BLOCK , FLOOR , ROOM )
	Accomodation Ilmu(1, "Ilmu", 6, 6, 4);
	/*
		Room Name format : I_blockNum - 0_floorNum - 0_roomNum
		Eg : I1-01-01
	*/

	// DECLARE WITH FORMAT ( ID , NAME , BLOCK , FLOOR , ROOM )
	Accomodation Amanah(2, "Amanah" , 6, 6, 4);
	/*
		Room Name format : A_blockNum - 0_floorNum - 0_roomNum
		Eg : A1-01-01
	*/

	// DECLARE WITH FORMAT ( ID , NAME , BLOCK , FLOOR , ROOM )
	Accomodation Cendi(3, "Cendekiawan",3, 10, 8);
	/*
		Room Name format : C_blockNum - 0_floorNum - 0_roomNum
		Eg : C1-01-01

		If the floor number is exactly 10,
		Room Name format : C_blockNum - 10 - 0_roomNum
		Eg : C1-10-02
	*/
	
	// DECLARE WITH FORMAT ( ID , NAME , BLOCK , FLOOR , ROOM )
	Accomodation Murni(4, "Murni", 3, 10, 8);
	/*
		Room Name format : M_blockNum - 0_floorNum - 0_roomNum
		Eg : M1-01-01

		If the floor number is exactly 10,
		Room Name format : M_blockNum - 10 - 0_roomNum
		Eg : M1-10-02
	*/

	// ALL IN ONE
	Accomodation All_Accomodation[4] = { Ilmu,Amanah,Cendi,Murni };

	static Customer stud = Student_X();
	system("cls");

	// Variable Declaration BEGIN
	int selection = 0;
	int accomodation_id;
	int block_no;
	int floor_no;
	int room_no;
	int m_or_y = 0;
	int period;
	// Variable Declaration END

	while (selection != 4){
		cout << "Student Name : "; stud.GetName(); cout << endl;
		cout << "Student ID   : "; stud.GetID();   cout << endl;
		cout << "Selection options from below :\n 1. Reserve Room \t 2. Cancel Reserve \t 3. Display My Reserved Room \t 4. Logout\nSelection : "; cin >> selection;

		if (selection == 1) {

			Sleep(2000);
			system("cls");

			accomodation_id = getAccomodationId();

			Sleep(2000);
			system("cls");

			cout << "Which block did you want :\n";
			switch (accomodation_id) {
				case 1:
					for (int i = 0; i < All_Accomodation[accomodation_id-1].GetBlock(); i++) {
						cout << i << ". I" << i + 1 << endl;
					}
					break;
				case 2:
					for (int i = 0; i < All_Accomodation[accomodation_id-1].GetBlock(); i++) {
						cout << i << ". A" << i + 1 << endl;
					}
					break;
				case 3:
					for (int i = 0; i < All_Accomodation[accomodation_id-1].GetBlock(); i++) {
						cout << i << ". C" << i + 1 << endl;
					}
					break;
				case 4:
					for (int i = 0; i < All_Accomodation[accomodation_id-1].GetBlock(); i++) {
						cout << i << ". M" << i + 1 << endl;
					}
					break;
			}
			block_no = getParticular(All_Accomodation[accomodation_id-1].GetBlock());

			Sleep(2000);
			system("cls");

			cout << "Which floor did you want :\n";
			for (int i = 0; i < All_Accomodation[accomodation_id-1].GetFloor(); i++) {
				cout << i << ". Floor " << i + 1 << endl;
			}
			floor_no = getParticular(All_Accomodation[accomodation_id-1].GetFloor());

			Sleep(2000);
			system("cls");

			while (m_or_y < 1 || m_or_y > 2) {
				cout << "How you are going to rent the room?\n 1. Calculate by Semester\n 2. Calculate by Years\nHow : "; cin >> m_or_y;
				if (m_or_y == 1) {
					cout << endl << "( Price per semesters : " << All_Accomodation[accomodation_id-1].GetPrice(m_or_y) << " )" << endl;
					cout << "How many months : "; cin >> period;
				}
				if (m_or_y == 2) {
					cout << endl << "( Price per years : " << All_Accomodation[accomodation_id-1].GetPrice(m_or_y) << " )" << endl;
					cout << "How many years  : "; cin >> period;
				}
			}

			Sleep(2000);
			system("cls");

			cout << "Available Room : " << endl;
			switch (accomodation_id) {
				case 1:
					All_Accomodation[accomodation_id - 1].GetAvailableRoom(block_no,floor_no);
					break;
				case 2:
					All_Accomodation[accomodation_id - 1].GetAvailableRoom(block_no, floor_no);
					break;
				case 3:
					All_Accomodation[accomodation_id - 1].GetAvailableRoom(block_no, floor_no);
					break;
				case 4:
					All_Accomodation[accomodation_id - 1].GetAvailableRoom(block_no, floor_no);
					break;
			}

			if (stud.Owned() == 0){
				cout << "Which room you wish to reserve?" << endl;
				room_no = getParticular(All_Accomodation[accomodation_id - 1].GetRoom());

				All_Accomodation[accomodation_id-1] = stud.Reserve(All_Accomodation[accomodation_id-1], block_no, floor_no, room_no, period, m_or_y);
			}
			else {
				cout << "You already owned a room..." << endl;
			}
			cout << "Please wait a moment...";
			Sleep(5000);
			system("cls");
		}


		else if (selection == 2) {
			int traced_accomodation_id;

			if (stud.GetOwnedRoom()[0] == 'I')
				traced_accomodation_id = 1;
			else if (stud.GetOwnedRoom()[0] == 'A')
				traced_accomodation_id = 2;
			else if (stud.GetOwnedRoom()[0] == 'C')
				traced_accomodation_id = 3;
			else if (stud.GetOwnedRoom()[0] == 'M')
				traced_accomodation_id = 4;

			int traced_blockNo = stud.GetOwnedRoom()[1] - '0' - 1;

			int traced_floorNo;
			if (stud.GetOwnedRoom()[3] == '0')
				traced_floorNo = stud.GetOwnedRoom()[4] - '0' - 1;
			else if (stud.GetOwnedRoom()[3] == '1')
				traced_floorNo = 9;

			int traced_roomNo;
			traced_roomNo = stud.GetOwnedRoom()[7] - '0' - 1;

			All_Accomodation[traced_accomodation_id-1] = stud.Cancel_Reserve(All_Accomodation[traced_accomodation_id-1], traced_blockNo, traced_floorNo, traced_roomNo);
			m_or_y = 0;

			Sleep(5000);
			system("cls");
		}


		else if (selection == 3) {
			cout << "\nMy reserved room : " << stud.GetOwnedRoom() << endl;
			cout << "Rent price : ";
			stud.GetRent();

			Sleep(5000);
			system("cls");
		}

		else if (selection == 4) {
			cout << "\nHave a good day, Bye.";
		}
	}
}