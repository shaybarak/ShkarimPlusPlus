#pragma once

#include "Faculty.h"

class FOHFaculty : public Faculty {
protected:
	// The FOH Faculty passes only tuition messages to students
	bool isRelevant(University::MessageType messageType) const;
	University::FacultyType FOHFaculty::getType() const;
};
