#include "Calendar.h"
#include <iostream>

int main() {
	
	Calendar* calendar = new Calendar();
	bool cont = true;			// trigger to stop loop
	//unsigned int weekDay;
	int weekDay, newWeekDay;
	const Appointment* app;
	Appointment::DayTime startTime, endTime, newStartTime, newEndTime;
	string subject;
	unsigned int c;

	cout << "Welcome to apointment diary!" << endl;

	while (cont) {
		cout << "	0: Add Appointment"		<< endl
			 << "	1: Remove Appointment"	<< endl
			 << "	2: Find Appointment"	<< endl
			 << "	3: Move appointment"	<< endl
			 << "	4: Print Calendar"		<< endl
			 << "Enter your choice: ";
		cin >> c;

		try {
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
					if (endTime <= startTime) {
						cout << "Error! appointment end time " << endTime 
							<< "must be more than start time " << startTime << endl;
						break;
					}
    				cin.ignore();
    				getline(cin, subject);
    				app = new Appointment(subject, startTime, endTime);
    				try {
    					calendar->addAppointment(weekDay, app);
    				} catch(string strEx) {
    					cout << strEx;
    				}    
    				break;

    			case 1:
    				cout << "Enter day for appointment, 1-Sunday...7-saturday" << endl;
    				cin >> weekDay;
    				cout << "Enter start hour for appointment [0-23]" << endl;
    				cin >> startTime.first;
    				cout << "Enter start minute for appointment [0-59]" << endl;
    				try {
    					calendar->removeAppointment(weekDay, startTime);
						cout << "Appointment removed successfully!" << endl;
    				} catch (string strEx) {
    					cout << strEx;
						break;
    				} 
    				break;
    
    			case 2:
    				// Find appointment
    				cout << "Enter day for appointment, 1-Sunday...7-saturday" << endl;
    				cin >> weekDay;
    				cout << "Enter start hour for appointment [0-23]" << endl;
    				cin >> startTime.first;
    				cout << "Enter start minute for appointment [0-59]" << endl;
    				cin >> startTime.second;
    				app = calendar->findAppointment(weekDay, startTime);
    				if (app != NULL) {
    					cout << *app << endl;
    				} else {
    					cout << "Appointment not found!" << endl;
    				}
    				break;
    
    			case 3:
    				cout << "Enter current day for appointment, 1-Sunday...7-saturday" << endl;
    				cin >> weekDay;
    				cout << "Enter current start hour for appointment [0-23]" << endl;
    				cin >> startTime.first;
    				cout << "Enter current start minute for appointment [0-59]" << endl;
    				cin >> startTime.second;
    				cout << "Enter new day for appointment, 1-Sunday...7-saturday" << endl;
    				cin >> newWeekDay;
    				cout << "Enter new start hour for appointment [0-23]" << endl;
    				cin >> newStartTime.first;
    				cout << "Enter new start minute for appointment [0-59]" << endl;
    				cin >> newStartTime.second;
    				cout << "Enter new end hour for appointment [0-23]" << endl;
    				cin >> newEndTime.first;
    				cout << "Enter new end minute for appointment [0-59]" << endl;
    				cin >> newEndTime.second;
    				calendar->duplicateAppointment(weekDay, startTime, newWeekDay, newStartTime, newEndTime);
    				break;
    
    			case 4:
    				cout << *calendar;
    				break;
    
    			default:
    				cont = false;
    				break;
    		}
		} catch (char* message) {
    	    cerr << "Error: " << message << endl;   
		}
	}

	return 0;
}

