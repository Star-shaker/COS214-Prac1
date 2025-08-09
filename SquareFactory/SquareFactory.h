// ConcreteCreator (Factory Method)

#ifndef SquareFactory_H
#define SquareFactory_H

#include "ShapeFactory/ShapeFactory.h"
#include "Square/Square.h"

#include <iostream>
#include <string>
using namespace std;

class SquareFactory : public ShapeFactory
{
    public:
        SquareFactory();
        virtual ~SquareFactory();
        
        Shape* createShape();
        void toString();
};

#endif