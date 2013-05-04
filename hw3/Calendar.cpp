#include <set>
#include <iomanip>
#include <iostream>
#include "Calendar.h"

#define COLUMN_SIZE 10

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
	cout << setw(7 * (COLUMN_SIZE + 2)) << setfill('-') << "" << endl;
	cout << "     |SUNDAY    |MONDAY    |TUESDAY   |WEDNESDAY |THURSDAY  |FIRDAY   |SATURDAY  |" << endl;
	for (set<Appointment::DayTime>::iterator iter = allTimes.begin(); iter != allTimes.end(); iter++) {
		cout << setw(7 * (COLUMN_SIZE + 2)) << setfill('-') << "" << endl;

		cout << setw(2) << setfill('0') << iter->first << ":" << setw(2) << setfill('0') << iter->second;

		for (int i = 0; i < 7; i++) {
			const Appointment* app = days[i].findAppointment(*iter);
			subject = (app == NULL ? "" : app->getSubject());
			cout << left << "|" << subject << "|" << endl;
		}
	}
	cout << setw(7 * (COLUMN_SIZE + 2)) << setfill('-') << "" << endl;
}

