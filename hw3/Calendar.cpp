#include <set>
#include <iomanip>
#include <iostream>
#include "Calendar.h"

#define COLUMN_SIZE 15
#define TIME_SIZE 5
#define SUBJECT_PROMPT "Subject:"
#define PRINT_DAY(x) setw(COLUMN_SIZE+1) << setfill(' ') << x
#define PRINT_LINE setw(7 * (COLUMN_SIZE + 1) + TIME_SIZE + 1) << setfill('-') << ""

void Calendar::addAppointment(int weekDay, const Appointment* appointment) {
	if (weekDay < 1 || weekDay > 7) {
		throw "Week day out of range!";
	}
	days[weekDay-1].addAppointment(appointment);
}

void Calendar::removeAppointment(int weekDay, const Appointment::DayTime& startTime) {
	if (weekDay < 1 || weekDay > 7) {
		throw "Week day out of range!";
	}
	days[weekDay-1].removeAppointment(startTime);
}

const Appointment* Calendar::findAppointment(int weekDay, const Appointment::DayTime& startTime) const {
	if (weekDay < 1 || weekDay > 7) {
		throw "Week day out of range!";
	}
	return days[weekDay-1].findAppointment(startTime);
}

ostream& Calendar::print(ostream& os) const{
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
	os << PRINT_LINE << endl;
	os << left << setw(TIME_SIZE) << setfill(' ') << "" 
		<< PRINT_DAY("|SUNDAY") << PRINT_DAY("|MONDAY") << PRINT_DAY("|TUESDAY") << PRINT_DAY("|WEDNESDAY")
		<< PRINT_DAY("|THURSDAY") << PRINT_DAY("|FRIDAY") << PRINT_DAY("|SATURDAY") << "|" << endl;

	for (set<Appointment::DayTime>::iterator iter = allTimes.begin(); iter != allTimes.end(); iter++) {
		os << PRINT_LINE << endl;
		os << right << (*iter);

		for (int i = 0; i < 7; i++) {
			const Appointment* app = days[i].findAppointment(*iter);
			subject = (app == NULL ? "" : SUBJECT_PROMPT + app->getSubject());
			if (subject.length() > COLUMN_SIZE) {
				subject = subject.substr(0, COLUMN_SIZE-3) + "...";
			}
			os << left << "|" << setw(COLUMN_SIZE) << setfill(' ') << subject;
		}
		os << "|" << endl;
	}
	return os << PRINT_LINE << endl << endl;
}

const Appointment* Calendar::duplicateAppointment(
	int currentWeekDay, const Appointment::DayTime& currentStartTime, int newWeekDay,
	const Appointment::DayTime& newStartTime, const Appointment::DayTime& newEndTime) {

	const Appointment* currentAppointment = findAppointment(currentWeekDay, currentStartTime);
	if (currentAppointment == NULL) {
		throw "Current appointment not found!";
	}
	Appointment* newAppointment = new Appointment(currentAppointment->getSubject(), newStartTime, newEndTime);
	addAppointment(newWeekDay, newAppointment);
	return newAppointment;
}

ostream& operator<<(ostream& os, Calendar& calendar) {
	return calendar.print(os);
}
