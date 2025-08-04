#include "ExportCanvas.h"

void ExportCanvas::_export(Canvas* canvas)
{
    this->canvas = canvas;
    prepareCanvas();
    renderElements();
    saveToFile();
}

ExportCanvas::~ExportCanvas()
{
    // TODO : Memory management!
}