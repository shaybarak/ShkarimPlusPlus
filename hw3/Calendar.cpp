#include <set>
#include <iomanip>
#include <iostream>
#include "Calendar.h"

void Calendar::print() {
	set<Appointment::DayTime> allTimes;
	int maxSubjectLen = 0;

	//find all appointments times
	for (int i = 0; i < 7; i++) {
		//TODO decide on modifiers here, as appointments is private...
		const Day::AppMap& appMap = days[i].getAllAppointments();
		for (Day::AppMap::iterator iter = appMap.begin(); iter != appMap.end(); iter++) {
			allTimes.insert(iter->first);
			maxSubjectLen = max(maxSubjectLen, iter->second.getSubject().len());
		}
	}

	//print all lines
	string subject;
	for (set<Appointment::DayTime>::iterator iter = allTimes.begin(); iter != allTimes.end(); iter++) {
		cout << printLine(cout, maxSubjectLen);
		cout << setw(maxSubjectLen) << setfill(' ');
		for (int i = 0; i < 7; i++) {
			const Appointment* app = days[i].findAppointment(*iter);
			subject = (app == NULL ? "" : app->getSubject());
			cout << left << "| " << subject << " |" << endl;
		}
	}
	cout << printLine(cout, maxSubjectLen) << endl;
}

ostream& Calendar::printLine(ostream& os, int subjectLen) {
	return os << setw(7 * (subjectLen + 1)) << setfill('-') << "" << endl;
}

