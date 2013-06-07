#include "Faculty.h"
#include "University.h"

Faculty::Faculty() {
	University::getInstance().attach(this);
}

University::MessageType Faculty::getLastChangeType() const {
	return University::getInstance().getLastChangeType();
}

unsigned int Faculty::getTuition() const {
	return University::getInstance().getTuition();
}

void Faculty::update(Subject* university) {
	if (isRelevant(University::getInstance().getLastChangeType())) {
		// Notify all students of relevant messages
		notify();
	}
}
