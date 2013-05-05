#include "Calendar.h"
#include <iostream>

int main() {
	
	Calendar* calendar = new Calendar();
	bool cont = true;			// trigger to stop loop
	//unsigned int weekDay;
	int weekDay, newWeekDay;
	const Appointment* app;
	const Appointment* newApp;
	Appointment::DayTime startTime, endTime;
	string subject;
	unsigned int c;

	cout << "Welcome to appinment dairy! Got milk?    " << endl; //TODO remove, maybe
	cout <<	"                                   ____      " << endl;
	cout <<	"        .        .                / ._ \\     " << endl;
	cout <<	"        |\\_,--._/|               / /  \\OOO   " << endl;
	cout <<	"         \\_/..\\_/      *MOOOW*   | |  _OOO_  " << endl;
	cout <<	"           )oo(                  | | / | | \\ " << endl;
	cout <<	"           \\\\//                  | | |     | " << endl;
	cout <<	"            ||__________        / /  +-30  | " << endl;
	cout <<	"            |          \\`.     / /   |     | " << endl;
	cout <<	"            \\  )        ) \\   / /    +-20  | " << endl;
	cout <<	"             ||`---(  || /|\\ / /     |     | " << endl;
	cout <<	"             ||     OO||----' /      +-10  | " << endl;
	cout <<	"             ||     '.||-----'      /       \\" << endl;
	cout <<	"            /__\\     /__\\           \\._____./" << endl;


	while (cont) {
		cout << "	What you want to do?"	<< endl //TODO re-phrase
			 << "	0: Add Appointment"		<< endl
			 << "	1: Remove Appointment"	<< endl
			 << "	2: Find Appointment"	<< endl
			 << "	3: Move appointment"	<< endl
			 << "	4: Print Calendar"		<< endl
			 << "Enter your choice: ";
		cin >> c;

		switch (c) {
			case 0:
				cout << "Enter day for appointment, 1-Sunday...7-saturday" << endl;
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
				cout << "Enter day for appointment, 1=Sunday...7-saturday" << endl;
				cin >> weekDay;
				cout << "Enter start hour for appointment [0-23]" << endl;
				cin >> startTime.first;
				cout << "Enter start minute for appointment [0-59]" << endl;
				calendar->removeAppointment(weekDay, startTime); //TODO rtry and catch
				calendar->addAppointment(weekDay, app);
				break;

			case 2:
				// Find appointment
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

			case 3:
				// Find existing appointment
				cout << "Enter day for appointment, 1=Sunday...7-saturday" << endl;
				cin >> weekDay;
				cout << "Enter start hour for appointment [0-23]" << endl;
				cin >> startTime.first;
				cout << "Enter start minute for appointment [0-59]" << endl;
				cin >> startTime.second;
				app = calendar->findAppointment(weekDay, startTime);
				if (app == NULL) {
					cout << "Appointment not found!" << endl;
					break;
				}
				// Create new appointment
				cout << "Enter new day for appointment, 1=Sunday...7-saturday" << endl;
				cin >> newWeekDay;
				cout << "Enter new start hour for appointment [0-23]" << endl;
				cin >> startTime.first;
				cout << "Enter new start minute for appointment [0-59]" << endl;
				cin >> startTime.second;
				cout << "Enter new end hour for appointment [0-23]" << endl;
				cin >> endTime.first;
				cout << "Enter new end minute for appointment [0-59]" << endl;
				cin >> endTime.second;
				newApp = new Appointment(app->getSubject(), startTime, endTime);
				// Replace existing appointment with new appointment
				calendar->removeAppointment(weekDay, app->getStartTime());
				calendar->addAppointment(newWeekDay, newApp);
				break;

			case 4:
				calendar->print();
				break;

			default:
				cont = false;
				break;
		}
	}

	return 0;
}

