// ConcreteCreator (Factory Method)

#ifndef TextboxFactory_H
#define TextboxFactory_H

#include "ShapeFactory.h"
#include "Textbox.h"

#include <iostream>
#include <string>
using namespace std;

class TextboxFactory : public ShapeFactory
{
    private:
        string text;
    public:
        TextboxFactory(string text);
        virtual Shape* createShape(int l, int w, int x, int y, string colour);
        void setText(string text);
        string toString();
};

#endif