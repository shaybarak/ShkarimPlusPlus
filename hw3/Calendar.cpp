#include <set>
#include "Calendar.h"

void Calendar::print() {
	set<Appointment::DayTime> allTimes;
	int maxSubjectLen = 0;
	for (int i = 0; i < 7; i++) {
		Day::AppMap::iterator iter = days[i].getAppointmentIter();
		//TODO decide on modifiers here, as appointments is private...
		for (iter = days[i].appointments.begin(); iter != appointments.end(); iter++) {
			
		}
	}

	//now print all lines
	for (set<Appointment::DayTime>::iterator iter = allTimes.begin(); iter != allTimes.end(); iter++) {
		for (int i = 0; i < 7; i++) {
			app = 
		}
	}
}
