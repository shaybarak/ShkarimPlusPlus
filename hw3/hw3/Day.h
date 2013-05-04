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

	Day() {}
	Day(Day& rhs);
	void addAppointment(const Appointment& appointment);
	void removeAppointment(const Appointment::DayTime& startTime);
	const Appointment& findAppointment(const Appointment::DayTime& startTime) const;

private:
	// Maps appointment start time to appointment
	map<Appointment::DayTime, Appointment*> appointments;
};
