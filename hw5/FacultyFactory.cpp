#include "FacultyFactory.h"
#include "FOHFaculty.h"
#include "ESFFaculty.h"
#include <assert.h>

Faculty* FacultyFactory::create(University* university, University::FacultyType type) {
	Faculty* faculty = NULL;
	switch (type) {
	case University::FOH:
		faculty = new FOHFaculty(university);
		break;
	case University::ESF:
		faculty = new ESFFaculty(university);
		break;
	default:
		assert(false);
	}
	return faculty;
}