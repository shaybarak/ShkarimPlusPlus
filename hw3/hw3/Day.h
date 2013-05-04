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

	typedef map<Appointment::DayTime, Appointment*> Appointments;

	Day() {}
	Day(const Day& rhs);
	void addAppointment(const Appointment& appointment);
	void removeAppointment(const Appointment::DayTime& startTime);
	Appointment* const findAppointment(const Appointment::DayTime& startTime) const;

private:
	// Maps appointment start time to appointment
	Appointments appointments;
};
