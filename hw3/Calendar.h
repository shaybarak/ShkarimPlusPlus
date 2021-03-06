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
	virtual const Appointment* duplicateAppointment(
		int currentWeekDay, const Appointment::DayTime& currentStartTime, int newWeekDay,
		const Appointment::DayTime& newStartTime, const Appointment::DayTime& newEndTime);
	virtual ostream& print(ostream& os) const;

private:
	Day days[7];
};

ostream& operator<<(ostream& os, const Calendar& calendar);

#endif
