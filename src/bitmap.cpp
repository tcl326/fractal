#include <fstream>
#include "bitmap.h"
#include "bitmap_info_header.h"
#include "bitmap_file_header.h"

namespace fractal_bitmap
{
    Bitmap::Bitmap(int width, int height) : width_(width), height_(height), p_pixels_(new std::uint8_t[height * width * 3]{})
    {
    }
    bool Bitmap::write(std::string filename)
    {
        fractal_bitmap::BitmapFileHeader file_header;
        fractal_bitmap::BitmapInfoHeader info_header;

        file_header.file_size = sizeof(fractal_bitmap::BitmapFileHeader) + sizeof(fractal_bitmap::BitmapInfoHeader) + width_ * height_ * 3;
        file_header.data_offset = sizeof(fractal_bitmap::BitmapFileHeader) + sizeof(fractal_bitmap::BitmapInfoHeader);

        info_header.width = width_;
        info_header.height = height_;

        std::ofstream file;

        file.open(filename, std::ios::out | std::ios::binary);

        if (!file)
        {
            return false;
        }

        file.write((char *)&file_header, sizeof(file_header));
        file.write((char *)&info_header, sizeof(info_header));
        file.write((char *)p_pixels_.get(), width_ * height_ * 3);

        file.close();

        if (!file)
        {
            return false;
        }
        return true;
    }
    void Bitmap::setPixel(int x, int y, std::uint8_t red, std::uint8_t green, std::uint8_t blue)
    {
        std::uint8_t *p_pixels = p_pixels_.get();
        p_pixels += (y * 3) * width_ + (x * 3);
        p_pixels[0] = blue;
        p_pixels[1] = green;
        p_pixels[2] = red;
    }
    Bitmap::~Bitmap() {}
} // namespace fractal_bitmap