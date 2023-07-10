// date: 10/07/2023
// author: samuel chamalé

#include "renderer.h"

namespace renderer
{
    Framebuffer::Framebuffer(int width, int height)
        : width(width), height(height), data(width * height, clearColor) {}
    // |2| how the hell data is initialized with clearColor?

    int Framebuffer::getWidth() const { return width; }

    int Framebuffer::getHeight() const { return height; }

    color::Color Framebuffer::getPixel(const Pixel &p) const
    {
        return data[p.y * width + p.x];
    }

    void Framebuffer::setPixel(const Pixel &p)
    {
        if (isInside(p))
            data[p.y * width + p.x] = currentColor;
    }

    void Framebuffer::clear()
    {
        std::fill(data.begin(), data.end(), clearColor); // |1| std::fill
        // TODO : use memset instead
    }

    bool Framebuffer::isInside(const Pixel &p) const
    {
        return p.x >= 0 && p.x < width && p.y >= 0 && p.y < height; // Check if the pixel is inside the framebuffer
    }

    // some global default variables, to avoid passing them around
    color::Color clearColor(0, 0, 0);
    color::Color currentColor(255, 255, 255);
}

// notes:
// |1| std::fill fills a range of elements in a container with a given value
// |2| data is a vector of color::Color, so it is a vector of colors,
// and it is initialized with a vector of size width * height, filled with clearColor
// this is a constructor initialization list, it is used to initialize member variables of a class