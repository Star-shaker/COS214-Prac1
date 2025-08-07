// ConcreteCreator (Factory Method)

#ifndef SquareFactory_H
#define SquareFactory_H

#include "ShapeFactory/ShapeFactory.h"
#include "Square/Square.h"

class SquareFactory : public ShapeFactory
{
    public:
        void toString();
        virtual ~SquareFactory();
        SquareFactory();
};

#endif