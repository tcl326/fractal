#include "zoom_list.h"

namespace fractal_zoom
{
    ZoomList::ZoomList(int width, int height) : width_(width), height_(height){};
    void ZoomList::add(const Zoom &zoom)
    {
        zooms.push_back(zoom);
        x_center_ += (zoom.x - width_ / 2) * scale_;
        y_center_ += (zoom.y - height_ / 2) * scale_;
        scale_ *= zoom.scale;
    };
    std::pair<double, double> ZoomList::doZoom(int x, int y)
    {
        double x_fractal = (x - width_ / 2) * scale_ + x_center_;
        double y_fractal = (y - height_ / 2) * scale_ + y_center_;
        return std::pair<double, double>(x_fractal, y_fractal);
    };

} // namespace fractal_zoom