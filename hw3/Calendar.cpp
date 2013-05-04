#include <set>
#include "Calendar.h"

void Calendar::print() {
	set<Appointment::DayTime> allTimes;
	int maxSubjectLen = 0;
	for (int i = 0; i < 7; i++) {
		//TODO decide on modifiers here, as appointments is private...
		const Day::AppMap& appMap = days[i].getAppMap();
		for (Day::AppMap::iterator iter = appMap.begin(); iter != appMap.end(); iter++) {
			allTimes.insert(iter->first);
		}
	}

	//now print all lines
	for (set<Appointment::DayTime>::iterator iter = allTimes.begin(); iter != allTimes.end(); iter++) {
		for (Day::WeekDay weekDay = Day::SUNDAY; weekDay <= Day::SATURDAY; i++) {
			Appointment* const app = days[weekDay].findAppointment(*iter);
		}
	}
}
