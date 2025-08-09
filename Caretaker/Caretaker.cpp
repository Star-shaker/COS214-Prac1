#include "Caretaker.h"

void Caretaker::storeMemento(Memento* memento) { // add void infront of the function
    this->canvasses.push_front(memento);
}

Memento* Caretaker::retrieveMemento() { // add Memento* infront of the function
    if (this->canvasses.empty()) {
        return NULL;
    }
    Memento* out = this->canvasses.front();
    this->canvasses.pop_front();
    return out;
}

// The pop_front function does not return anything 
// as it is a void function that is why the error occurs
// Maybe try to get the first element first and then pop?