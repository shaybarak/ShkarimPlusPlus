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

	typedef map<Appointment::DayTime, Appointment*> AppMap;

	Day() {}
	void addAppointment(const Appointment& appointment);
	void removeAppointment(const Appointment::DayTime& startTime);
	const Appointment& findAppointment(const Appointment::DayTime& startTime) const;
	const map<Appointment::DayTime, Appointment*>::iterator getAppointmentIter() const;

private:
	// Disallow copy constructor
	Day(Day& rhs) {}

	// Maps appointment start time to appointment
	AppMap appointments;
}
