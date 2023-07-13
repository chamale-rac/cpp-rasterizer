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

            // handle first endpoint
            int xend = round(p0.x);                        // The x-coordinate of the pixel where the line ends
            double yend = p0.y + gradient * (xend - p0.x); // The y-coordinate of the pixel where the line ends
            double xgap = rfpart(p0.x + 0.5);              // The "weight" of the first pixel (i.e., the amount of the line that passes through the pixel)
            int xpxl1 = xend;                              // The x-coordinate of the first pixel
            int ypxl1 = ipart(yend);                       // The y-coordinate of the first pixel

            if (steep)
            {
                fb.setPixel(gl::Pixel(ypxl1, xpxl1), rfpart(yend) * xgap);
                fb.setPixel(gl::Pixel(ypxl1 + 1, xpxl1), fpart(yend) * xgap);
            }
            else
            {
                fb.setPixel(gl::Pixel(xpxl1, ypxl1), rfpart(yend) * xgap);
                fb.setPixel(gl::Pixel(xpxl1, ypxl1 + 1), fpart(yend) * xgap);
            }

            double intery = yend + gradient; // first y-intersection for the main loop

            // handle second endpoint
            xend = round(p1.x);
            yend = p1.y + gradient * (xend - p1.x);
            xgap = fpart(p1.x + 0.5);
            int xpxl2 = xend;
            int ypxl2 = ipart(yend);

            if (steep)
            {
                fb.setPixel(gl::Pixel(ypxl2, xpxl2), rfpart(yend) * xgap);
                fb.setPixel(gl::Pixel(ypxl2 + 1, xpxl2), fpart(yend) * xgap);
            }
            else
            {
                fb.setPixel(gl::Pixel(xpxl2, ypxl2), rfpart(yend) * xgap);
                fb.setPixel(gl::Pixel(xpxl2, ypxl2 + 1), fpart(yend) * xgap);
            }
            // TODO: return to int the pixel coordinates and remove floor in framebuffer setPixel

            // main loop

            if (steep)
            {
                for (int x = xpxl1 + 1; x <= xpxl2 - 1; x++)
                {
                    fb.setPixel(gl::Pixel(ipart(intery), x), rfpart(intery));
                    fb.setPixel(gl::Pixel(ipart(intery) + 1, x), fpart(intery));
                    intery = intery + gradient;
                }
            }
            else
            {
                for (int x = xpxl1 + 1; x <= xpxl2 - 1; x++)
                {
                    fb.setPixel(gl::Pixel(x, ipart(intery)), rfpart(intery));
                    fb.setPixel(gl::Pixel(x, ipart(intery) + 1), fpart(intery));
                    intery = intery + gradient;
                }
            }
        }
    }
}

// reminders:
// |1| link: https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm