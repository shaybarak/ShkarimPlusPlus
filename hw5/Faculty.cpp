#include "Faculty.h"
#include "University.h"

Faculty::Faculty(University* university) {
	sbj = university;
	sbj->attach(this);
}

Faculty::~Faculty() {
	sbj->detach(this);
}

University::MessageType Faculty::getLastChangeType() const {
	return dynamic_cast<University*>(sbj)->getLastChangeType();
}

unsigned int Faculty::getTuition() const {
	return dynamic_cast<University*>(sbj)->getTuition();
}

void Faculty::update(Subject* sbj) {
	if (sbj == this->sbj) {
		if (isRelevant(dynamic_cast<University*>(sbj)->getLastChangeType())) {
			notify();
		}
	}
}
