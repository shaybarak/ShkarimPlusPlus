#ifndef OBSERVER_H
#define OBSERVER_H

#include "Subject.h"

class Observer {
public:
    virtual void notify(Subject* s) = 0;
    virtual ~Observer() {};
};

#endif
