#include "Caretaker.h"

Caretaker::storeMemento(Memento* memento) {
    this->canvasses.push_front(memento);
}

Caretaker::retrieveMemento() {
    return this->canvasses.pop_front();
}