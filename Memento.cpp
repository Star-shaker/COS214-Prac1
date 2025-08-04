#include "Memento.h"

Memento::Memento(std::vector<Shape*>& elements) {
    this->shapes = elements; // shapes is now copy of elements
}

std::vector<Shape*> Memento::getState() {
    return this->shapes;
}