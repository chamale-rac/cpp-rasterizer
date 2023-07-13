#include "polygon.h"
#include "line.h"

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
    }
}