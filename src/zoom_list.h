#ifndef FRACTAL_ZOOM_LIST_H_
#define FRACTAL_ZOOM_LIST_H_

#include <vector>
#include <utility>
#include "zoom.h"

namespace fractal_zoom
{
    class ZoomList
    {
    private:
        double x_center_{0};
        double y_center_{0};
        double scale_{1.0};

        int width_{0};
        int height_{0};
        std::vector<Zoom> zooms;

    public:
        ZoomList(int width, int height);
        void add(const Zoom &zoom);
        std::pair<double, double> doZoom(int x, int y);
    };
} // namespace fractal_zoom

#endif