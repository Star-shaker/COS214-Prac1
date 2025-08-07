// ConcretePrototype (Prototype)
// ConcreteProduct (Factory Method)

#ifndef TEXTBOX
#define TEXTBOX

#include "Shape/Shape.h"

class Textbox: public Shape {
    private:
        std::string text;
    public:
        Textbox(int x, int y, int l, int w, std::string colour, std::string text);
        virtual Shape* clone();
        virtual std::string shapeType();
        std::string getText();
};

#endif