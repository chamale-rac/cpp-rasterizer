#pragma once

#include "gl.h"

namespace draw
{
    void line(gl::Framebuffer &fb, gl::Pixel &p0, gl::Pixel &p1);
    void polygon(gl::Framebuffer &fb, std::vector<gl::Pixel> &vertices);
    void fillPolygon(gl::Framebuffer &fb, std::vector<gl::Pixel> &vertices);
}