#pragma once

#include "Observer.h"
#include "Subject.h"
#include "University.h"

class Faculty : public Observer, public Subject {
public:
	Faculty();
	University::MessageType getLastChangeType() const;
	unsigned int getTuition() const;

	void update(Subject* subject);

protected:
	// Message filter, returns true to pass to students
	virtual bool isRelevant(University::MessageType messageType) const = 0;
};
