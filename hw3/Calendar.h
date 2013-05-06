#ifndef CALENDAR_H
#define CALENDAR_H

#include "Day.h"
using namespace std;

class Calendar {
public:
	// Parameter weekDay is 1..7 for Sunday..Saturday
	virtual void addAppointment(int weekDay, const Appointment* appointment);  // Takes ownership of appointment
	virtual void removeAppointment(int weekDay, const Appointment::DayTime& startTime);
	virtual const Appointment* findAppointment(int weekDay, const Appointment::DayTime& startTime) const;
	virtual void print() const;

private:
	Day days[7];
};

#endif
