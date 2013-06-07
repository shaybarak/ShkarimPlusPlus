#include "Subject.h"
#include "Observer.h"

using namespace std;

void Subject::attach(Observer* ob) { 
	m_observers.push_back(ob); 
} 

void Subject::detach(Observer* ob) { 
	unsigned int i = 0;
	for (i = 0; i < m_observers.size(); i++) {
		if (m_observers[i] == ob) break;
	}
	m_observers.erase(m_observers.begin() + i); 
} 

void Subject::notify() { 
	for (unsigned int i = 0; i < m_observers.size(); i++) {
		(m_observers[i])->update(this);
	}
}
