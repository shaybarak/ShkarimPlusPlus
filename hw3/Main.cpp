#include "Calendar.h"
#include <iostream>

int main() {
	
	Calendar calendar();
	bool cont	= true;			// trigger to stop loop
	unsigned int weekDay;
	Appointment* app;
	Appointment::DayTime startTime, endTime;
	string subject;
	unsigned int c;

	cout << "Welcome to appinment dairy! Got milk?" << endl; //TODO remove

	while (cont) {
		cout << "	What you want to do?"	<< endl //TODO re-phrase
			 << "	0: Add Appointment"		<< endl
			 << "	1: Remove Appointment"	<< endl
			 << "	2: Find Appointment"	<< endl
			 << "   3: Move appointment"	<< endl
			 << "Enter your choice: ";
		cin >> c;

		switch (c) {
			case 0:
				cout << "Enter day for appointment, 1=Sunday...7-saturday" << endl;
				cin >> weekDay;
				weekDay--;
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
			case 1:
				
				break;

//noam hear!
///////////////////////////////////////////////////////////////////////////////////////////////////
//shay hear!

			default:
				cont = false;
				break;
		}
	}

	return 0;
}
