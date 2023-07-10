// date: 10/07/2023
// author: samuel chamalé

#pragma once
#include "color.h"
#include <vector>

namespace renderer
{
    struct Pixel
    {
        int x, y;
        Pixel(int x = 0, int y = 0) : x(x), y(y) {}
    };

    class Framebuffer
    {
    public:
        Framebuffer(int width, int height);
        int getWidth() const;
        int getHeight() const;
        color::Color getPixel(const Pixel &p) const;
        void setPixel(const Pixel &p);
        void clear();

    private:
        int width, height;
        std::vector<color::Color> data;
        bool isInside(const Pixel &p) const;
    };

    extern color::Color clearColor;
    extern color::Color currentColor;
}