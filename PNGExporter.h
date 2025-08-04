#ifndef PNGExporter_H
#define PNGExporter_H

#include "ExportCanvas.h"

class PNGExporter : public ExportCanvas
{
    private:
        void saveToFile();
        void prepareCanvas();
        void renderElements();

    public:
        virtual ~PNGExporter();
};

#endif