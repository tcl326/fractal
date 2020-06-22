#ifndef FRACTAL_ZOOM_H_
#define FRACTAL_ZOOM_H_

namespace fractal_zoom
{
    struct Zoom
    {
        int x{0};
        int y{0};
        double scale{0.0};
        Zoom(int x, int y, double scale) : x(x), y(y), scale(scale){};
    };
} // namespace fractal_zoom

#endif