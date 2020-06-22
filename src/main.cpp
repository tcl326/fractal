//============================================================================
// Name        : Fractal.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <math.h>
#include "bitmap.h"
#include "mandelbrot.h"
#include "zoom_list.h"
#include "fractal_creator.h"

int main()
{
    int const HEIGHT = 600;
    int const WIDTH = 800;

    FractalCreator fractal_creator(WIDTH, HEIGHT);

    fractal_bitmap::Bitmap bitmap(WIDTH, HEIGHT);

    fractal_zoom::ZoomList zoom_list(WIDTH, HEIGHT);

    zoom_list.add(fractal_zoom::Zoom(WIDTH / 2, HEIGHT / 2, 4.0 / WIDTH));

    zoom_list.add(fractal_zoom::Zoom(295, HEIGHT - 202, 0.1));

    zoom_list.add(fractal_zoom::Zoom(312, HEIGHT - 304, 0.1));

    std::unique_ptr<int[]>
    histogram(new int[fractal_mandelbrot::Mandelbrot::MAX_ITERATIONS]{});
    std::unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{});

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {

            std::pair<double, double> coords = zoom_list.doZoom(x, y);

            double x_fractal = coords.first;
            double y_fractal = coords.second;

            int iterations = fractal_mandelbrot::Mandelbrot::getIterations(x_fractal, y_fractal);

            fractal[y * WIDTH + x] = iterations;

            if (iterations < fractal_mandelbrot::Mandelbrot::MAX_ITERATIONS)
            {
                histogram[iterations]++;
            }
        }
    }
    int total = 0;

    for (int i = 0; i < fractal_mandelbrot::Mandelbrot::MAX_ITERATIONS; i++)
    {
        total += histogram[i];
    }

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            std::uint8_t red = 0;
            std::uint8_t green = 0;
            std::uint8_t blue = 0;

            int iterations = fractal[y * WIDTH + x];
            double hue = 0.0;

            if (iterations < fractal_mandelbrot::Mandelbrot::MAX_ITERATIONS)
            {

                for (int i = 0; i <= iterations; i++)
                {
                    hue += ((double)histogram[i]) / total;
                }

                green = pow(255, hue);
            }

            bitmap.setPixel(x, y, red, green, blue);
        }
    }

    bitmap.write("test.bmp");

    std::cout << "finished" << std::endl;

    return 0;
}
