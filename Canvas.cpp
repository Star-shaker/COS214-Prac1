#include "Canvas.h"

Memento* Canvas::captureCurrent() {
    return new Memento(this->shapes);
}

void Canvas::undoAction(Memento* memento) {
    this->shapes = memento->getState();
}