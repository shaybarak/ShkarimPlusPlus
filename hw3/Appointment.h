#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include <vector>

using namespace std;

class Appointment {
public:
	typedef pair<int, int> DayTime;

	Appointment(const string& subject, const DayTime& startTime, const DayTime& endTime);
	virtual void destroy() const { delete this; }
	
	// Equality is defined by the exercise instructions as having intersecting times
	virtual bool operator==(const Appointment& rhs) const;

	virtual const string& getSubject() const { return subject; }
	virtual DayTime getStartTime() const { return startTime; }
	virtual DayTime getEndTime() const { return endTime; }

protected:
	// Disallow stack allocation
	~Appointment() {}

private:
	const string subject;
	const DayTime startTime;
	const DayTime endTime;
};

#endif
