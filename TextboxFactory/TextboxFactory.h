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
    private:
        string text;
    public:
        TextboxFactory();
        TextboxFactory(string text);
        
        Shape* createShape();
        virtual Shape* createShape(int l, int w, int x, int y, string colour);
        void setText(string text);
};

#endif