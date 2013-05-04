#include "Calendar.h"
#include <iostream>

int main() {
	
	Calendar* calendar = new Calendar();
	bool cont = true;			// trigger to stop loop
	//unsigned int weekDay;
	unsigned char weekDay;
	const Appointment* app;
	Appointment::DayTime startTime, endTime;
	string subject;
	unsigned int c;

	cout << "Welcome to appointent dairy! Got milk?   " << endl; //TODO remove, maybe
	cout <<	"	                           ____       " << endl
		 <<	"	.        .                / ._ \      " << endl
		 <<	"   |\_,--._/|               / /  \OOO    " << endl
		 <<	"    \_/..\_/      *MOOOW*   | |  _OOO_   " << endl
		 <<	"      )oo(                  | | / | | \  " << endl
		 <<	"      \\//                  | | |     |  " << endl
		 <<	"		||__________        / /  +-30  |  " << endl
		 <<	"		|          \`.     / /   |     |  " << endl
		 <<	"		\  )        ) \   / /    +-20  |  " << endl
		 <<	"        ||`---(  || /|\ / /     |     |  " << endl
		 <<	"        ||     OO||----' /      +-10  |  " << endl
		 <<	"        ||     '.||-----'      /       \ " << endl
		 <<	"       /__\     /__\           \._____./ " << endl;


	while (cont) {
		cout << "	What you want to do?"	<< endl //TODO re-phrase
			 << "	0: Add Appointment"		<< endl
			 << "	1: Remove Appointment"	<< endl
			 << "	2: Find Appointment"	<< endl
			 << "   3: Move appointment"	<< endl
			 << "   4: Print Calendar"		<< endl
			 << "Enter your choice: ";
		cin >> c;

		switch (c) {
			case 0:
				cout << "Enter day for appointment, 1=Sunday...7-saturday" << endl;
				cin >> weekDay;
				cout << "Enter start hour for appointment [0-23]" << endl;
				cin >> startTime.first;
				cout << "Enter start minute for appointment [0-59]" << endl;
				cin >> startTime.second;
				cout << "Enter end hour for appointment [0-23]" << endl;
				cin >> endTime.first;
				cout << "Enter end minute for appointment [0-59]" << endl;
				cin >> endTime.second;
				cout << "Enter subject for appointment" << endl;
				cin >> subject;
				app = new Appointment(subject, startTime, endTime);
				calendar->addAppointment(weekDay, app);
				break;
			case 1:
				
				break;

//noam hear!
///////////////////////////////////////////////////////////////////////////////////////////////////
//shay hear!

			case 2:
				cout << "Enter day for appointment, 1=Sunday...7-saturday" << endl;
				cin >> weekDay;
				cout << "Enter start hour for appointment [0-23]" << endl;
				cin >> startTime.first;
				cout << "Enter start minute for appointment [0-59]" << endl;
				cin >> startTime.second;
				app = calendar->findAppointment(weekDay, startTime);
				if (app != NULL) {
					cout << app << endl;
				} else {
					cout << "Appointment not found!" << endl;
				}
				break;

			default:
				cont = false;
				break;
		}
	}

	return 0;
}
