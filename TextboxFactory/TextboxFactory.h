// ConcreteCreator (Factory Method)

#ifndef TextboxFactory_H
#define TextboxFactory_H

#include "ShapeFactory/ShapeFactory.h"
#include "Textbox/Textbox.h"

#include <iostream>
#include <string>
using namespace std;

class TextboxFactory : public ShapeFactory
{
    public:
        TextboxFactory();
        virtual ~TextboxFactory();
        
        Shape* createShape();
        void toString();
};

#endif