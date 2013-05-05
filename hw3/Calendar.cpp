#include <set>
#include <iomanip>
#include <iostream>
#include "Calendar.h"

#define COLUMN_SIZE 15
#define TIME_SIZE 5
#define SUBJECT_PROMPT "NOSHA:" //TODO change to subject
#define PRINT_DAY(x) setw(COLUMN_SIZE+1) << setfill(' ') << x
#define PRINT_LINE setw(7 * (COLUMN_SIZE + 1) + TIME_SIZE + 1) << setfill('-') << ""

void Calendar::addAppointment(int weekDay, const Appointment* appointment) {
	days[weekDay-1].addAppointment(appointment);
}

void Calendar::removeAppointment(int weekDay, const Appointment::DayTime& startTime) {
	days[weekDay-1].removeAppointment(startTime);
}

const Appointment* Calendar::findAppointment(int weekDay, const Appointment::DayTime& startTime) const {
	return days[weekDay-1].findAppointment(startTime);
}

void Calendar::print() const{
	set<Appointment::DayTime> allTimes;

	//find all appointments times
	for (int i = 0; i < 7; i++) {
		const Day::Appointments& appMap = days[i].getAllAppointments();
		for (Day::Appointments::const_iterator iter = appMap.begin(); iter != appMap.end(); ++iter) {
			allTimes.insert(iter->first);
		}
	}

	//print all lines
	string subject;
	cout << PRINT_LINE << endl;
	cout << left << setw(TIME_SIZE) << setfill(' ') << "" 
		<< PRINT_DAY("|SUNDAY") << PRINT_DAY("|MONDAY") << PRINT_DAY("|TUESDAY") << PRINT_DAY("|WEDNESDAY")
		<< PRINT_DAY("|THURSDAY") << PRINT_DAY("|FRIDAY") << PRINT_DAY("|SATURDAY") << "|" << endl;

	for (set<Appointment::DayTime>::iterator iter = allTimes.begin(); iter != allTimes.end(); iter++) {
		cout << PRINT_LINE << endl;
		cout << right << setw(2) << setfill('0') << iter->first << ":" << setw(2) << setfill('0') << iter->second;

		for (int i = 0; i < 7; i++) {
			const Appointment* app = days[i].findAppointment(*iter);
			subject = (app == NULL ? "" : SUBJECT_PROMPT + app->getSubject());
			if (subject.length() > COLUMN_SIZE) {
				subject = subject.substr(0, COLUMN_SIZE-3) + "...";
			}
			cout << left << "|" << setw(COLUMN_SIZE) << setfill(' ') << subject;
		}
		cout << "|" << endl;
	}
	cout << PRINT_LINE << endl << endl;
}

