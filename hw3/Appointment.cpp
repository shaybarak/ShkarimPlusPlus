#include "Appointment.h"

Appointment::Appointment(const string& subject, const DayTime& startTime, const DayTime& endTime)
	: subject(subject), startTime(startTime), endTime(endTime) {
		if (endTime < startTime) {
			throw "Appointments must have a positive duration!";
		}
}

bool Appointment::operator==(const Appointment& rhs) const {
	// Appointments intersect if the span of one appointment contains the start time
	// or the end time of the other appointment.
	// Note that the span is defined as [start, end) to support back-to-back meetings.
	return ((startTime <= rhs.startTime && endTime > rhs.startTime)
		||  (startTime <= rhs.endTime && endTime > rhs.endTime));
}

ostream& operator<<(ostream& os, const Appointment& appointment) {
	os << appointment.getSubject() << " - "
		<< appointment.getStartTime().first << ":" << appointment.getStartTime().second << "-"
		<< appointment.getEndTime().first << ":" << appointment.getEndTime().second;
	return os;
}
