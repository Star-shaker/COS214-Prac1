#ifndef TextBoxFactory_H
#define TextBoxFactory_H

#include "ShapeFactory.h"
#include "Textbox.h"

class TextBoxFactory : public ShapeFactory
{
    public:
        Shape* createShape();
        void toString();
        virtual ~TextBoxFactory();
};

#endif