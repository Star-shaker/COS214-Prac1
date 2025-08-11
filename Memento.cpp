#include "Memento.h"

Memento::~Memento() 
{ 
    for (Shape* shape : shapes)
    {
        if (shape != nullptr) 
        {
            delete shape;
            shape = nullptr;
        }
    }
}

Memento::Memento(std::vector<Shape*>& elements) 
{
    for (Shape* shape : elements) 
    {
        this->shapes.push_back(shape->clone());
    }
}

std::vector<Shape*> Memento::getState() 
{
    return this->shapes;
}