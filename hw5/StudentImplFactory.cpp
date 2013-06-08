#include "StudentImplFactory.h"
#include "StudentImpl.h"

Student* StudentImplFactory::create(const string& name, University::FacultyType facultyType) {
	StudentImpl* impl = NULL;
	switch (facultyType) {
	case University::ESF:
		impl = new StudentImpl(name, University::getESFFaculty());
	case University::FOH:
		impl = new StudentImpl(name, University::getFOHFaculty());
	}
	return impl;
}
