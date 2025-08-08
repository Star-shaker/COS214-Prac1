// Prototype (Prototype)
// Product (Factory Method)

#ifndef SHAPE_H
#define SHAPE_H

#include <string> 
#include <vector>

class Shape 
{
    private:
        int length;
        int width;
        std::string colour;
        int position_x;
        int position_y;
        
    public:
        Shape(int x, int y, int l, int w, std::string);
        virtual std::string shapeType() = 0;
        virtual Shape* clone() = 0;
        std::vector<int> getCoords();
};

#endif 