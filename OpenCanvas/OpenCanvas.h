// Client (Main)

#ifndef OpenCanvas_H
#define OpenCanvas_H

#include "Canvas/Canvas.h"
#include "ExportCanvas/ExportCanvas.h"

#include <list>
#include <iostream>
#include <string>
using namespace std;

class OpenCanvas
{
    private:
        list<Canvas*> canvasses;
    
    public:
        OpenCanvas(bool test);
        ~OpenCanvas();
        void testCanvas();
        void exportToFile(Canvas canvas);
        Canvas* createCanvas();
        list<Canvas*> listCanvasses();

};

#endif