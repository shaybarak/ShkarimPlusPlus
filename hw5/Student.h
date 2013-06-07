#pragma once

#include "Observer.h"
#include <string>

using namespace std;

class StudentFactory;
class StudentImpl;
class Faculty;

class Student : public Observer {
	// Instances may only be created through the StudentFactory
	friend class StudentFactory;

private:
	// Register to a faculty
	Student(const string& name, const StudentImpl& impl, Faculty& faculty);
	const string& name;
	const StudentImpl& impl;
};
