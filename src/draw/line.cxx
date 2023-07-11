#include "line.h"
#include <cmath>

namespace draw
{
    namespace details
    {
        // integer part of x
        int ipart(double x)
        {
            return static_cast<int>(std::floor(x));
        }

        // round x to nearest integer
        int round(double x)
        {
            return ipart(x + 0.5);
        }

        // fractional part of x
        double fpart(double x)
        {
            return x - std::floor(x);
        }

        // 1 - fractional part of x
        double rfpart(double x)
        {
            return 1.0 - fpart(x);
        }

        void line(gl::Framebuffer &fb, gl::Pixel &p0, gl::Pixel &p1, const gl::Color &c)
        {
            // TODO: Xiaolin Wu's line algorithm |1|
            bool steep = std::abs(p1.y - p0.y) > std::abs(p1.x - p0.x);

            if (steep)
            {
                std::swap(p0.x, p0.y);
                std::swap(p1.x, p1.y);
            }
            if (p0.x > p1.x)
            {
                std::swap(p0.x, p1.x);
                std::swap(p0.y, p1.y);
            }

            double dx = p1.x - p0.x;
            double dy = p1.y - p0.y;

            // TODO investigate about float and double inner workings
            double gradient = dy / dx; // intensity of the color
            if (dx == 0.0)             // this means the line is vertical
            {
                gradient = 1.0;
            }

            int xend = round(p0.x);                        // The x-coordinate of the pixel where the line ends
            double yend = p0.y + gradient * (xend - p0.x); // The y-coordinate of the pixel where the line ends
            double xgap = rfpart(p0.x + 0.5);              // The "weight" of the first pixel (i.e., the amount of the line that passes through the pixel)
            int xpxl1 = xend;                              // The x-coordinate of the first pixel
            int ypxl1 = ipart(yend);                       // The y-coordinate of the first pixel

            // TODO: pending plot function and color interpolation
        }
    }
}

// reminders:
// |1| link: https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm