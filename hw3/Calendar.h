#ifndef CALENDAR_H
#define CALENDAR_H

#include "Day.h"
using namespace std;

class Calendar {
public:
	Calendar() {}
	// Parameter weekDay is 1..7 for Sunday..Saturday
	void addAppointment(int weekDay, const Appointment* appointment);
	void removeAppointment(int weekDay, const Appointment::DayTime& startTime);
	const Appointment* findAppointment(int weekDay, const Appointment::DayTime& startTime) const;
	void print() const;

private:
	Day days[7];
};

#endif
