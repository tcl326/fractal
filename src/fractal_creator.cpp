#include "fractal_creator.h"
#include "mandelbrot.h"

FractalCreator::FractalCreator(int width, int height) : width_(width), height_(height), histogram_(new int[fractal_mandelbrot::Mandelbrot::MAX_ITERATIONS]), fractal_(new int[width * height]), bitmap_(width, height), zoom_list_(width, height){};

FractalCreator::~FractalCreator(){};
void FractalCreator::calculateIteration(){};
void FractalCreator::drawFractal(){};
void FractalCreator::addZoom(const fractal_zoom::Zoom &zoom)
{
    zoom_list_.add(zoom);
};
void FractalCreator::writeBitmap(std::string name){};
