#include "ShapeFactory.h"

Shape* ShapeFactory::anOperation()
{
    shape = createShape();
    cout << "Factory called:  " << shape->shapeType() << endl;
}