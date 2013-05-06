#ifndef DAY_H
#define DAY_H

#include "Appointment.h"
#include <map>
using namespace std;

class Day {
public:
	typedef map<Appointment::DayTime, const Appointment*> Appointments;

	Day() {}
	Day(const Day& rhs);
	~Day();
	virtual void addAppointment(const Appointment* appointment);  // Takes ownership of appointment
	virtual void removeAppointment(const Appointment::DayTime& startTime);
	virtual const Appointment* findAppointment(const Appointment::DayTime& startTime) const;
	virtual const Appointments& getAllAppointments() const { return appointments; }

private:
	// Maps appointment start time to appointment
	Appointments appointments;
};

#endif
