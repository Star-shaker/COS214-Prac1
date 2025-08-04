#ifndef SquareFactory_H
#define SquareFactory_H

#include "ShapeFactory.h"

class SquareFactory : public ShapeFactory
{
    public:
        Shape* createShape();
        void toString();
        virtual ~SquareFactory();
};

#endif