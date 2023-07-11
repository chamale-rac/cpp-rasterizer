#pragma once
#include "gl.h"

namespace draw
{
    namespace details
    {
        void line(gl::Framebuffer &fb, gl::Pixel &p0, gl::Pixel &p1, const gl::Color &c);
    } // namespace line
}