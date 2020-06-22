
#ifndef FRACTAL_BITMAP_FILE_HEADER_H_
#define FRACTAL_BITMAP_FILE_HEADER_H_

#include <cstdint>

namespace fractal_bitmap
{
    struct BitmapFileHeader
    {
        char header[2]{'B', 'M'};
        std::int32_t file_size;
        std::int32_t reserved{0};
        std::int32_t data_offset;
    };
} // namespace fractal_bitmap

#endif /* FRACTAL_BITMAP_FILE_HEADER_H_ */