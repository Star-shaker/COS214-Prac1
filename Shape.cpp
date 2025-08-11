#include "Shape.h"

Shape::Shape(int x, int y, int l, int w, std::string colour) 
{
    this->position_x = x;
    this->position_y = y;
    this->length = l;
    this->width = w;
    this->colour = colour;
}

string Shape::getCoords() 
{
    string coords = "(" + to_string(position_x) + "," + to_string(position_y) + ")";
    return coords;
}