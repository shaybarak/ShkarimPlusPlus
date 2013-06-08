#include "Student.h"
#include "StudentImpl.h"
#include "Faculty.h"

Student::Student(const string& name, Faculty* faculty) {
	sbj = faculty;
	sbj->attach(this);
	impl = StudentImplFactory::create(name, faculty->getType());
}

Student::~Student() {
	sbj->detach(this);
	delete impl;
}

void Student::update(Subject* subject) {
	impl->announceUpdate(dynamic_cast<Faculty*>(subject));
}
