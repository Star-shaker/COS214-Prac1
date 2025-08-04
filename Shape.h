#ifndef SHAPE
#define SHAPE

#include <string> 

class Shape {
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
};

#endif 