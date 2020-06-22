#ifndef FRACTAL_FRACTAL_CREATOR_H_
#define FRACTAL_FRACTAL_CREATOR_H_

#include <string>
#include <memory>
#include "zoom.h"
#include "zoom_list.h"
#include "bitmap.h"

class FractalCreator
{
private:
    int width_;
    int height_;
    std::unique_ptr<int[]> histogram_;
    std::unique_ptr<int[]> fractal_;
    fractal_zoom::ZoomList zoom_list_;
    fractal_bitmap::Bitmap bitmap_;

public:
    FractalCreator(int width, int height);
    virtual ~FractalCreator();
    void calculateIteration();
    void drawFractal();
    void addZoom(const fractal_zoom::Zoom &zoom);
    void writeBitmap(std::string name);
};

#endif