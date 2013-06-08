#include "StudentImplFactory.h"
#include "ESFStudentImpl.h"
#include "FOHStudentImpl.h"

StudentImpl* StudentImplFactory::create(const string& name, University::FacultyType facultyType) {
	StudentImpl* impl = NULL;
	switch (facultyType) {
	case University::ESF:
		impl = new ESFStudentImpl(name);
	case University::FOH:
		impl = new FOHStudentImpl(name);
	}
	return impl;
}
