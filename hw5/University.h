#pragma once

#include "Subject.h"
#include <time.h>

// University implements the singleton behavior
class University : public Subject {
public:
	enum MessageType {
		NONE,
		TUITION,
		LECTURE_CANCELLED,
	};

	enum FacultyType {
		FOH,
		ESF,
	};


	static University& getInstance() { return instance; }

	MessageType getLastChangeType() const { return lastChange; }
	void changeTuition(unsigned int newTuition);
	unsigned int getTuition() const { return tuition; }
	void cancelTomorrowsLecture();

private:
	University(unsigned int tuition) : lastChange(NONE), tuition(tuition) {}
	University(const University&);
	void operator=(University& rhs);

	static University instance;

	MessageType lastChange;
	unsigned int tuition;
};
