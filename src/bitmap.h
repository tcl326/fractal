#ifndef FRACTAL_BITMAP_H_
#define FRACTAL_BITMAP_H_

#include <cstdint>
#include <string>

namespace fractal_bitmap
{
    class Bitmap
    {
    private:
        int width_{0};
        int height_{0};
        std::unique_ptr<std::uint8_t[]> p_pixels_{nullptr};

    public:
        Bitmap(int width, int height);
        void setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue);
        bool write(std::string filename);
        virtual ~Bitmap();
    };
} // namespace fractal_bitmap

#endif