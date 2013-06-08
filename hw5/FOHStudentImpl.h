#pragma once

#include "StudentImpl.h"

class FOHStudentImpl : public StudentImpl {

public:
	FOHStudentImpl(const string& name) :  StudentImpl(name) {};
};