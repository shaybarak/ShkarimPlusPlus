#include "Day.h"

Day::Day(const Day& rhs) {
	// Copy the appointments map
	for (Appointments::iterator it = appointments.begin(); it != appointments.end(); it++) {
		appointments[it->first] = new Appointment(*it->second);
	}
}
