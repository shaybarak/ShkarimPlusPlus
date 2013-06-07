#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include "Subject.h"

class University : public Subject {
public:
	static University& getInstance() { return instance; }

private:
	University() {}                   // Disallow instantiation
	University(const University&);    // Disallow copying
	void operator=(University& rhs);  // Disallow assignment

	static University instance;
};

#endif
