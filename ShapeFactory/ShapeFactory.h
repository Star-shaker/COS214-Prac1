#ifndef ShapeFactory_H
#define ShapeFactory_H

#include "Shape/Shape.h"

class ShapeFactory
{
    protected:
        Shape* addShape();
        virtual Shape* createShape() = 0;
        ShapeFactory(){};
        virtual ~ShapeFactory() {};
        virtual void toString() = 0;
};

#endif 

// TODO: Maybe add a function so that the createShape() function is actually called