// date: 10/07/2023
// author: samuel chamalé

#pragma once
#include "color.h"
#include <vector>

namespace framebuffer
{
    class Framebuffer
    {
    public:
        Framebuffer(int width, int height);
        int getWidth() const;
        int getHeight() const;
        color::Color getPixel(int x, int y) const;
        void setPixel(int x, int y);
        void clear();

    private:
        int width, height;
        std::vector<color::Color> data;
    };

    extern Framebuffer framebuffer;
    extern color::Color clearColor;
    extern color::Color currentColor;
}