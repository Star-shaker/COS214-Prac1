#include "Shape.h"

Shape::Shape(int x, int y, int l, int w, std::string colour) 
{
    this->position_x = x;
    this->position_y = y;
    this->length = l;
    this->width = w;
    this->colour = colour;
}

std::vector<int> Shape::getCoords() 
{
    std::vector<int> coords = {position_x, position_y};
    return coords;
}