#ifndef PDFExporter_H
#define PDFExporter_H

#include "ExportCanvas.h"

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