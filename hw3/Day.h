#ifndef DAY_H
#define DAY_H

#include "Appointment.h"
#include <map>
using namespace std;

class Day {
public:
	enum WeekDay {
		SUNDAY = 0,
		MONDAY,
		TUESDAY,
		WEDNESDAY,
		THURSDAY,
		FRIDAY,
		SATURDAY,
	};

	typedef map<Appointment::DayTime, const Appointment*> Appointments;

	Day() {}
	Day(const Day& rhs);
	~Day();
	void addAppointment(const Appointment& appointment);  // Takes ownership of appointment
	void removeAppointment(const Appointment::DayTime& startTime);
	const Appointment* findAppointment(const Appointment::DayTime& startTime) const;
	const Appointments& getAllAppointments() const { return appointments; }

private:
	// Maps appointment start time to appointment
	Appointments appointments;
};

#endif
