#include "FacultyFactory.h"
#include "FOHFaculty.h"
#include "ESFFaculty.h"

Faculty* FacultyFactory::create(FacultyType type) {
	Faculty* faculty = NULL;
	switch (type) {
	case FOH:
		faculty = new FOHFaculty();
	case ESF:
		faculty = new ESFFaculty();
	}
	return faculty;
}