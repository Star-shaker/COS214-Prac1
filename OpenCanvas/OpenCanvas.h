// Client (Main)

#ifndef OpenCanvas_H
#define OpenCanvas_H

#include "../Canvas/Canvas.h"
#include "ExportCanvas/ExportCanvas.h"
#include "Caretaker/Caretaker.h"

#include <list>
#include <iostream>
#include <string>
using namespace std;

class OpenCanvas
{
    private:
        list<Canvas*> canvasses;
        Caretaker* caretaker;
    public:
        OpenCanvas(bool test);
        ~OpenCanvas();
        void testCanvas();
        void exportToFile(Canvas canvas);
        Canvas* createCanvas();
        list<Canvas*> listCanvasses();
};

#endif