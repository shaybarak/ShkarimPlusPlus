#include "Student.h"
#include "StudentImpl.h"
#include "Faculty.h"

Student::Student(const string& name, const StudentImpl& impl, Faculty& faculty) : name(name), impl(impl) {
	faculty.attach(this);
}
