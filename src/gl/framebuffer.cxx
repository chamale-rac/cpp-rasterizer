// date: 10/07/2023
// author: samuel chamalé

#include "framebuffer.h"

namespace framebuffer
{
    Framebuffer::Framebuffer(int width, int height)
        : width(width), height(height), data(width * height, clearColor) {}
    // |2| how the hell data is initialized with clearColor?

    int Framebuffer::getWidth() const { return width; }

    int Framebuffer::getHeight() const { return height; }

    color::Color Framebuffer::getPixel(int x, int y) const
    {
        return data[y * width + x];
    }

    void Framebuffer::setPixel(int x, int y, const color::Color &c)
    {
        data[y * width + x] = c;
    }

    void Framebuffer::clear()
    {
        std::fill(data.begin(), data.end(), clearColor); // |1| std::fill
        // TODO : use memset instead
    }

    // some global default variables, to avoid passing them around
    Framebuffer framebuffer(800, 600);
    color::Color clearColor(0, 0, 0);
}

// notes:
// |1| std::fill fills a range of elements in a container with a given value
// |2| data is a vector of color::Color, so it is a vector of colors,
// and it is initialized with a vector of size width * height, filled with clearColor
// this is a constructor initialization list, it is used to initialize member variables of a class