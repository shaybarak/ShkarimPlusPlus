#pragma once

#include "Student.h"
#include <string>

using namespace std;

class StudentFactory;

class StudentImpl {
public:
	void announceUpdate(const string& name) const;

private:
	const string& name;
};
