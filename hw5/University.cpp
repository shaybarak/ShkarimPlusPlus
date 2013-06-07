#include "University.h"

void University::changeTuition(unsigned int newTuition) {
	tuition = newTuition;
	lastChange = TUITION;
	notify();
}

void University::cancelTomorrowsLecture() {
	lastChange = LECTURE_CANCELLED;
	notify();
}
