#include "Memento.h"

Memento::Memento(std::vector<Shape*>& elements) {
    this->shapes = elements; // shapes is now copy of elements
}