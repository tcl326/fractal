#ifndef FRACTAL_MANDELBROT_H_
#define FRACTAL_MANDELBROT_H_

namespace fractal_mandelbrot
{
    class Mandelbrot
    {
    public:
        Mandelbrot();
        virtual ~Mandelbrot();

        static int getIterations(double x, double y);

        static const int MAX_ITERATIONS = 1000;
    };
} // namespace fractal_mandelbrot

#endif
