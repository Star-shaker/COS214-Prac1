// ConcreteClass (Template Method)

#ifndef PDFExporter_H
#define PDFExporter_H

#include "ExportCanvas/ExportCanvas.h"

#include <iostream>
using namespace std;

class PDFExporter : public ExportCanvas
{
    private:
        void saveToFile();
        void prepareCanvas();
        void renderElements();
};

#endif