#ifndef ShapeFactory_H
#define ShapeFactory_H

#include "Shape.h"

class ShapeFactory : public Shape
{
    protected:
        virtual Shape* createShape() = 0;
        virtual ~ShapeFactory() {};
        virtual void toString() = 0;
};

#endif 