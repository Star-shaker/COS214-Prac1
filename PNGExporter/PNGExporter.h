// ConcreteClass (Template Method)

#ifndef PNGExporter_H
#define PNGExporter_H

#include "ExportCanvas/ExportCanvas.h"

#include <iostream>
using namespace std;

class PNGExporter : public ExportCanvas
{
    private:
        void saveToFile();
        void prepareCanvas();
        void renderElements();
};

#endif