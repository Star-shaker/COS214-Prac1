// Client (Main)

#ifndef OpenCanvas_H
#define OpenCanvas_H

#include "Canvas/Canvas.h"
#include "ExportCanvas/ExportCanvas.h"
#include "PDFExporter/PDFExporter.h"
#include "PNGExporter/PNGExporter.h"
#include "Caretaker/Caretaker.h"

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