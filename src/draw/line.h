#pragma once
#include "gl.h"

namespace draw
{
    namespace details
    {
        void line(gl::Framebuffer &fb, const gl::Pixel &p0, const gl::Pixel &p1);
    } // namespace line
}