#pragma once

#include "Faculty.h"

class FOHFaculty : public Faculty {
protected:
	// The FOH Faculty passes only tuition messages to students
	virtual bool isRelevant(University::MessageType messageType) const;
};
