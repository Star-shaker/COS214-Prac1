// ConcreteClass (Template Method)

#ifndef PDFExporter_H
#define PDFExporter_H

#include "ExportCanvas.h"

#include <iostream>
using namespace std;

class PDFExporter : public ExportCanvas
{
    private:
        void saveToFile();
        void prepareCanvas();
        void renderElements();
        
    public:
        virtual ~PDFExporter();
};

#endif