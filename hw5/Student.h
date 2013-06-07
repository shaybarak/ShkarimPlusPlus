#pragma once

#include "Observer.h"
#include <string>

using namespace std;

class StudentFactory;
class StudentImpl;
class Faculty;

class Student : public Observer {
public:
	Student(const string& name, const string& faculty);

private:
	const StudentImpl* impl;
};
