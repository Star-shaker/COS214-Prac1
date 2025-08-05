#include "Caretaker.h"

Caretaker::storeMemento(Memento* memento) { // add void infront of the function
    this->canvasses.push_front(memento);
}

Caretaker::retrieveMemento() { // add Memento* infront of the function
    return this->canvasses.pop_front();
}

// The pop_front function does not return anything 
// as it is a void function that is why the error occurs
// Maybe try to get the first element first and then pop?