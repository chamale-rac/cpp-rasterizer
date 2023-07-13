#pragma once

#include "gl.h"

namespace draw
{
    void line(gl::Framebuffer &fb, const gl::Pixel &p0, const gl::Pixel &p1);
    void polygon(gl::Framebuffer &fb, std::vector<gl::Pixel> &vertices);
    void fillPolygon(gl::Framebuffer &fb, std::vector<gl::Pixel> &vertices);
}