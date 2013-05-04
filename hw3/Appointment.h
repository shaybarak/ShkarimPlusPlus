#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include <vector>

using namespace std;

class Appointment {
public:
	typedef pair<int, int> DayTime;

	Appointment(const string& subject, const DayTime& startTime, const DayTime& endTime);
	// Equality is defined by the exercise instructions as having intersecting times
	bool operator==(const Appointment& rhs);
	void destroy() const { delete this; }

	const string& getSubject() const { return subject; }
	DayTime getStartTime() const { return startTime; }
	DayTime getEndTime() const { return endTime; }

protected:
	// Disallow stack allocation
	~Appointment() {}

private:
	const string subject;
	const DayTime startTime;
	const DayTime endTime;
};

#endif
