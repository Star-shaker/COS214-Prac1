#ifndef ExportCanvas_H
#define ExportCanvas_H

#include "Canvas.h"

class ExportCanvas : public Canvas
{
    private:
        Canvas* canvas;

        virtual void prepareCanvas() = 0;
        virtual void renderElements() = 0;
        virtual void saveToFile() = 0;
    
    public:
        virtual ~ExportCanvas();
        void exportToFile(Canvas* canvas); //Template method
};

#endif