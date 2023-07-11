#include "draw.h"

#include "line.h"
#include "polygon.h"

namespace draw
{
    void line(gl::Framebuffer &fb, gl::Pixel &p0, gl::Pixel &p1, const gl::Color &c)
    {
        details::line(fb, p0, p1, c);
    }

    void polygon(gl::Framebuffer &fb, const std::vector<gl::Pixel> &vertices, const gl::Color &c)
    {
        details::polygon(fb, vertices, c);
    }
}