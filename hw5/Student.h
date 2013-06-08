#pragma once

#include "Observer.h"
#include "StudentImplFactory.h"
#include <string>


using namespace std;

class StudentFactory;
class StudentImpl;
class Faculty;

class Student : public Observer {
public:
	Student(const string& name, Faculty* faculty);
	~Student();
	void update(Subject* subject);

private:
	const StudentImpl* impl;
};
