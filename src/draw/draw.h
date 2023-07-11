#pragma once

#include "gl.h"

namespace draw
{
    void line(gl::Framebuffer &fb, gl::Pixel &p0, gl::Pixel &p1, const gl::Color &c);
    void polygon(gl::Framebuffer &fb, const std::vector<gl::Pixel> &vertices, const gl::Color &c);
}