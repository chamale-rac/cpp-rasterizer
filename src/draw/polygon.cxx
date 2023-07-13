#include "polygon.h"
#include "line.h"

#include <limits>
#include <algorithm>
#include <cmath>

namespace draw
{
    namespace details
    {
        void polygon(gl::Framebuffer &fb, std::vector<gl::Pixel> &vertices, const gl::Color &c)
        {
            for (std::size_t i = 0; i < vertices.size(); ++i)
            {
                line(fb, vertices[i], vertices[(i + 1) % vertices.size()], c);
            }
        }

        void fillPolygon(gl::Framebuffer &fb, std::vector<gl::Pixel> &vertices, const gl::Color &c)
        {
            // Find the minimum and maximum y-coordinates of the polygon
            int ymin = std::numeric_limits<int>::max();
            int ymax = std::numeric_limits<int>::min();
            for (const auto &v : vertices)
            {
                ymin = std::min(ymin, v.y);
                ymax = std::max(ymax, v.y);
            }

            // Loop over each scanline
            for (int y = ymin; y <= ymax; ++y)
            {
                // Find the intersections of the scanline with each edge of the polygon
                std::vector<double> intersections;
                for (std::size_t i = 0; i < vertices.size(); ++i)
                {
                    const auto &v1 = vertices[i];
                    const auto &v2 = vertices[(i + 1) % vertices.size()];
                    if ((v1.y <= y && v2.y > y) || (v2.y <= y && v1.y > y))
                    {
                        double x = v1.x + (static_cast<double>(y - v1.y) / static_cast<double>(v2.y - v1.y)) * (v2.x - v1.x);
                        intersections.push_back(x);
                    }
                }

                // Sort the intersections by x-coordinate
                std::sort(intersections.begin(), intersections.end());

                // Draw horizontal lines between pairs of intersecting edges
                for (std::size_t i = 0; i < intersections.size(); i += 2)
                {
                    int x1 = std::max(0, static_cast<int>(std::floor(intersections[i])));
                    int x2 = std::min(fb.getWidth() - 1, static_cast<int>(std::floor(intersections[i + 1])));
                    for (int x = x1; x <= x2; ++x)
                    {
                        fb.setPixel(gl::Pixel(x, y), 1);
                    }
                }
            }
        }
    }
}