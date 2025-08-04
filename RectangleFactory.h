#ifndef RectangleFactory_H
#define RectangleFactory_H

#include "ShapeFactory.h"

class RectangleFactory : public ShapeFactory
{
    public:
        Shape* createShape();
        void toString();
        virtual ~RectangleFactory();
};

#endif