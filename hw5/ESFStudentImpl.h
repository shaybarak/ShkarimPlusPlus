#pragma once

#include "StudentImpl.h"

class ESFStudentImpl : public StudentImpl {

public:
	ESFStudentImpl(const string& name) :  StudentImpl(name) {};

protected:
	virtual const char* getTypeStr() const { return "ESF"; }
};
