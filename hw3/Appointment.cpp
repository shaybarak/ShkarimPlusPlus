#include "Appointment.h"

Appointment::Appointment(const string& subject, const DayTime& start, const DayTime& end)
	: subject(subject), start(start), end(end) {
		if (end < start) {
			throw "Appointments cannot end before they start";
		}
}
