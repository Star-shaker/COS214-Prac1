#include "Textbox.h"

Textbox::Textbox(int x, int y, int l, int w, std::string colour, std::string text): Shape(x, y, l, w, colour)
{
    this->position_x = x;
    this->position_y = y;
    this->length = l;
    this->width = w;
    this->colour = colour;
    this->text = text;
}

Shape* Textbox::clone() 
{
    return new Textbox(*this);
}

std::string Textbox::shapeType() 
{
    return "Textbox";
}

string Textbox::getAttributes()
{
    return "(l:" + to_string(length) + ", w:" + to_string(width) + ", colour:" + colour + ", text:" + text + ")";
}