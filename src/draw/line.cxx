#include "line.h"
#include <cmath>

namespace draw
{
    namespace details
    {
        // integer part of x
        int ipart(double x)
        {
            return std::floor(x);
        }

        // round x to nearest integer
        int round(double x)
        {
            return ipart(x + 0.5);
        }

        // fractional part of x
        double fpart(double x)
        {
            return x - ipart(x);
        }

        // 1 - fractional part of x
        double rfpart(double x)
        {
            return 1.0 - fpart(x);
        }

        void line(gl::Framebuffer &fb, gl::Pixel &p0, gl::Pixel &p1)
        {
            double x0 = p0.x;
            double y0 = p0.y;
            double x1 = p1.x;
            double y1 = p1.y;

            // TODO: Xiaolin Wu's line algorithm |1|
            bool steep = std::abs(y1 - y0) > std::abs(x1 - x0);

            if (steep)
            {
                std::swap(x0, y0);
                std::swap(x1, y1);
            }
            if (x0 > x1)
            {
                std::swap(x0, x1);
                std::swap(y0, y1);
            }

            double dx = x1 - x0;
            double dy = y1 - y0;

            double gradient;
            if (dx == 0.0)
            {
                std::cout << "dx == 0" << std::endl;
                gradient = 1.0;
            }
            else
            {
                gradient = dy / dx;
            }

            // handle first endpoint
            int xend = round(x0);                      // The x-coordinate of the pixel where the line ends
            double yend = y0 + gradient * (xend - x0); // The y-coordinate of the pixel where the line ends
            double xgap = rfpart(x0 + 0.5);            // The "weight" of the first pixel (i.e., the amount of the line that passes through the pixel)
            int xpxl1 = xend;                          // The x-coordinate of the first pixel
            int ypxl1 = ipart(yend);                   // The y-coordinate of the first pixel

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
            xend = round(x1);
            yend = y1 + gradient * (xend - x1);
            xgap = fpart(x1 + 0.5);
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