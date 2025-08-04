#ifndef MEMENTO
#define MEMENTO

#include "Shape.h"
#include <vector>

class Memento {
    private:
        std::vector<Shape*> shapes;
    public:
        Memento(vector<Shape*>& elements);
}

#endif