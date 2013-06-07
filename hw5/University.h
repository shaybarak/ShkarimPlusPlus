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

	static University& getInstance() { return instance; }

	MessageType getLastChangeType() const { return lastChange; }
	void changeTuition(unsigned int newTuition);
	unsigned int getTuition() const { return tuition; }
	void cancelTomorrowsLecture();

private:
	University() : lastChange(NONE), tuition(DEFAULT_TUITION) {}
	University(const University&);
	void operator=(University& rhs);

	static University instance;
	static const unsigned int DEFAULT_TUITION = 10000;

	MessageType lastChange;
	unsigned int tuition;
};
