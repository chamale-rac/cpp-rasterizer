#include "draw.h"

#include "line.h"
#include "polygon.h"

namespace draw
{
    void line(gl::Framebuffer &fb, const gl::Pixel &p0, const gl::Pixel &p1)
    {
        details::line(fb, p0, p1);
    }

    void polygon(gl::Framebuffer &fb, std::vector<gl::Pixel> &vertices)
    {
        details::polygon(fb, vertices);
    }

    void fillPolygon(gl::Framebuffer &fb, std::vector<gl::Pixel> &vertices)
    {
        details::fillPolygon(fb, vertices);
    }
}