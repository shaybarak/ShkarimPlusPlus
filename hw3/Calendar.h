#include "Day.h"
using namespace std;

class Calendar {
public:
	Calendar() {}
	void addAppointment(Day::WeekDay weekDay, const Appointment& appointment);
	void removeAppointment(Day::WeekDay weekDay, const Appointment::DayTime& startTime);
	const Appointment& findAppointment(Day::WeekDay weekDay, const Appointment::DayTime& startTime) const;
	void print();

private:
	Day days[7];
};
