#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

using namespace std;

class Subject {
public:
    virtual ~Subject() {};
    void register_observer(Observer* o);

protected:
    void notify_observers();

private:
    std::vector observers;
};

#endif
