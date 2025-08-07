// ConcreteClass (Template Method)

#ifndef PDFExporter_H
#define PDFExporter_H

#include "ExportCanvas/ExportCanvas.h"

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