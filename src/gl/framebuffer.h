// date: 10/07/2023
// author: samuel chamalé

#pragma once
#include "color.h"
#include "pixel.h"
#include <vector>

namespace framebuffer
{
    class Framebuffer
    {
    public:
        Framebuffer(int width, int height);
        int getWidth() const;
        int getHeight() const;
        color::Color getPixel(const pixel::Pixel &p) const;
        void setPixel(const pixel::Pixel &p);
        void clear();
        void renderBuffer() const;

    private:
        int width, height;
        std::vector<color::Color> data; // |1| std::vector
        bool isInside(const pixel::Pixel &p) const;
    };

    extern color::Color clearColor;
    extern color::Color currentColor;
}

// notes:
// |1| std::vector is a dynamic array, it can grow and shrink at runtime
// i used it here because it is more efficient than multidimensional array and easier than pointer to pointer