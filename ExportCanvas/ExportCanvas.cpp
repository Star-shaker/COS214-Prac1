#include "ExportCanvas.h"

void ExportCanvas::exportToFile(Canvas* canvas)
{
    this->canvas = canvas;
    prepareCanvas();
    renderElements();
    saveToFile();
}

ExportCanvas::~ExportCanvas() {}