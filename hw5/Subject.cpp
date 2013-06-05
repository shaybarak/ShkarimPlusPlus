#include "Subject.h"
#include "Observer.h"

using namespace std;

void Subject::notify_observers() {
    vector::iterator iter;
    for (iter = observers.begin(); iter != observers.end(); ++iter) {
        (*iter)->notify(this);
    }
}

void Subject::register_observer(Observer* o) {
    observers.push_back(o);
}
