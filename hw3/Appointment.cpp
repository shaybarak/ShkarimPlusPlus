#include "Appointment.h"
#include <iomanip>

Appointment::Appointment(const string& subject, const DayTime& startTime, const DayTime& endTime)
	: subject(subject), startTime(startTime), endTime(endTime) {
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
		<< appointment.getStartTime() << "-" << appointment.getEndTime();
	return os;
}

ostream& operator<<(ostream& os, const Appointment::DayTime& dayTime) {
	os << right << setw(2) << setfill('0') << dayTime.first
		<< ":" << setw(2) << setfill('0') << dayTime.second;
	return os;
}