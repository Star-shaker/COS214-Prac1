// Client (Main)

#ifndef OpenCanvas_H
#define OpenCanvas_H

#include "Canvas.h"
#include "ExportCanvas.h"
#include "PDFExporter.h"
#include "PNGExporter.h"
#include "Caretaker.h"

#include <list>
#include <iostream>
#include <string>
using namespace std;

class OpenCanvas
{
    private:
        Canvas* canvas;
        Caretaker* caretaker;
        
    public:
        OpenCanvas(bool test);
        ~OpenCanvas();
        Canvas* createCanvas();
        void testCanvas();
        void exportToFile(Canvas* canvas, int input);
        void storeCanvasState(Canvas* canvas);
};

#endif