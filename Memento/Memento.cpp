#include "Memento.h"

Memento::Memento(std::vector<Shape*>& elements) 
{
    for (int i = 0; i < elements.size(); i++) 
    {
        this->shapes.push_back(elements[i]->clone());
    }
}

std::vector<Shape*> Memento::getState() 
{
    return this->shapes;
}