#pragma once
#include "gl.h"

namespace draw
{
    namespace details
    {
        void polygon(gl::Framebuffer &fb, std::vector<gl::Pixel> &vertices);
        void fillPolygon(gl::Framebuffer &fb, std::vector<gl::Pixel> &vertices);
    } // namespace polygon
}