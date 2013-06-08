#pragma once

#include "Faculty.h"

class ESFFaculty : public Faculty {

public:
	ESFFaculty(University* university) : Faculty(university) {};

protected:
	// The ESF Faculty passes both tuition and lecture cancellation messages to students
	bool isRelevant(University::MessageType messageType) const;
	University::FacultyType ESFFaculty::getType() const;
};
