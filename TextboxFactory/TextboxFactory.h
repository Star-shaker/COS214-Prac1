#ifndef TextboxFactory_H
#define TextboxFactory_H

#include "ShapeFactory/ShapeFactory.h"
#include "Textbox/Textbox.h"

class TextboxFactory : public ShapeFactory
{
    public:
        Shape* createShape();
        void toString();
        virtual ~TextboxFactory();
};

#endif