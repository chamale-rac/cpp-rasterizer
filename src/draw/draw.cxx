#include "draw.h"

#include "line.h"
#include "polygon.h"

namespace draw
{
    void line(gl::Framebuffer &fb, gl::Pixel &p0, gl::Pixel &p1)
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