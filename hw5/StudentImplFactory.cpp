#include "StudentImplFactory.h"
#include "StudentImpl.h"

Student* StudentImplFactory::create(const string& name, const string& faculty) {
	StudentImpl* impl = NULL;
	if (faculty == "ESF") {
		impl = new StudentImpl(name, University::getESFFaculty());
	} else if (faculty == "FOH") {
		impl = new StudentImpl(name, University::getFOHFaculty());
	}
	return impl;
}
