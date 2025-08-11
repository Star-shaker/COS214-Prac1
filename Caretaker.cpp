#include "Caretaker.h"

void Caretaker::storeMemento(Memento* memento) 
{
    this->canvasses.push_front(memento);
}

Memento* Caretaker::retrieveMemento() 
{
    if (this->canvasses.empty()) 
    {
        return NULL;
    }

    Memento* out = this->canvasses.front();
    this->canvasses.pop_front();
    return out;
}

Caretaker::~Caretaker() 
{
    for (Memento* m : canvasses) 
    {
        if (m != nullptr) 
        {
            delete m;
            m = nullptr;
        }
    }
}