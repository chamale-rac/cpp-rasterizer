#include "draw.h"

#include "line.h"
#include "polygon.h"

namespace draw
{
    void line(gl::Framebuffer &fb, const gl::Pixel &p1, const gl::Pixel &p2, const gl::Color &c)
    {
        details::line(fb, p1, p2, c);
    }

    void polygon(gl::Framebuffer &fb, const std::vector<gl::Pixel> &vertices, const gl::Color &c)
    {
        details::polygon(fb, vertices, c);
    }
}