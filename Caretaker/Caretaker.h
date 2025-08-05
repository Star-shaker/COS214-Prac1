#ifndef CARETAKER
#define CARETAKER

#include "Memento/Memento.h"
#include <list>

class Caretaker {
    private:
        std::list<Memento*> canvasses;
    public:
        void storeMemento(Memento*);
        Memento retrieveMemento(); 
};

#endif