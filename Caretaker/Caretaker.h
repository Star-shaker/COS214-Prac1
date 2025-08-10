#ifndef CARETAKER_H
#define CARETAKER_H

#include "../Memento/Memento.h"

#include <list>

class Caretaker 
{
    private:
        std::list<Memento*> canvasses;
        
    public:
        ~Caretaker();
        void storeMemento(Memento*);
        Memento* retrieveMemento(); 
};

#endif