#include "Day.h"

Day::Day(const Day& rhs) {
	// Copy the appointments map
	for (Appointments::iterator it = appointments.begin(); it != appointments.end(); it++) {
		appointments[it->first] = new Appointment(*it->second);
	}
}

void Day::addAppointment(const Appointment& appointment) {
	for (Appointments::iterator it = appointments.begin(); it != appointments.end(); it++) {
		if (it->second == appointment) {
			throw "New appointment conflicts with existing appointment!";
		}
	}
	appointments[appointment.getStartTime()] = &appointment;
}

void Day::removeAppointment(const Appointment::DayTime& startTime) {
	Appointments::iterator it = appointments.find(startTime);
	if (it == appointments.end()) {
		throw "Appointment not found!";
	}
	appointments.erase(it);
	delete it->second;
}

Appointment* const Day::findAppointment(const Appointment::DayTime& startTime) {
	Appointments::iterator it = appointments.find(startTime);
	if (it == appointments.end()) {
		return NULL;
	}
	return it->second;
}
