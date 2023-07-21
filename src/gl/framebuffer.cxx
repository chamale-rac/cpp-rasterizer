// date: 10/07/2023
// author: samuel chamalé

#include "framebuffer.h"

#include <fstream>
#include <cstdint>

namespace framebuffer
{
    Framebuffer::Framebuffer(int width, int height, bool reverseY)
        : width(width), height(height), data(width * height, clearColor), reverseY(reverseY) {}
    // |2| how the hell data is initialized with clearColor?

    int Framebuffer::getWidth() const { return width; }

    int Framebuffer::getHeight() const { return height; }

    color::Color Framebuffer::getPixel(const pixel::Pixel &p) const
    {
        return data[p.y * width + p.x];
    }

    // receives: pixel, brightness
    void Framebuffer::setPixel(const pixel::Pixel &p, const double brightness = 1.0)
    {
        if (isInside(p))
        {
            // TODO: consider level of brightness to desire to include or not currentColor
            // TODO: consider which is the correct formula
            // TODO: consider a function to get the context color, it means the color in average of the adjacent pixels
            // data[(height - p.y) * width + p.x] = (data[(height - p.y) * width + p.x] + currentColor) * brightness;
            // TODO consider to return to just currentColor * brightness
            // TODO consider check the case the brightness is 0.0, also the case when the clearColor is equal to the background.
            // data[(height - p.y) * width + p.x] = currentColor * brightness;
            if (reverseY)
                data[(height - p.y) * width + p.x] = currentColor * brightness;
            else
                data[p.y * width + p.x] = currentColor * brightness;
        }
    }

    void Framebuffer::clear()
    {
        std::fill(data.begin(), data.end(), clearColor); // |1| std::fill
        // TODO : use memset instead
    }

    bool Framebuffer::isInside(const pixel::Pixel &p) const
    {
        return p.x >= 0 && p.x < width && p.y >= 0 && p.y < height; // Check if the pixel is inside the framebuffer
    }

    void Framebuffer::renderBuffer(const std::string fileName) const
    {
        std::ofstream out(fileName, std::ios::binary);

        // BMP header
        uint16_t fileType = 0x4D42;
        uint32_t fileSize = 54 + width * height * 3;
        uint16_t reserved1 = 0;
        uint16_t reserved2 = 0;
        uint32_t offset = 54;
        uint32_t headerSize = 40;
        uint32_t imageWidth = width;
        uint32_t imageHeight = height;
        uint16_t planes = 1;
        uint16_t bitsPerPixel = 24;
        uint32_t compression = 0;
        uint32_t imageSize = width * height * 3;
        uint32_t xPixelsPerMeter = 0;
        uint32_t yPixelsPerMeter = 0;
        uint32_t totalColors = 0;
        uint32_t importantColors = 0;

        out.write((char *)&fileType, sizeof(fileType));
        out.write((char *)&fileSize, sizeof(fileSize));
        out.write((char *)&reserved1, sizeof(reserved1));
        out.write((char *)&reserved2, sizeof(reserved2));
        out.write((char *)&offset, sizeof(offset));
        out.write((char *)&headerSize, sizeof(headerSize));
        out.write((char *)&imageWidth, sizeof(imageWidth));
        out.write((char *)&imageHeight, sizeof(imageHeight));
        out.write((char *)&planes, sizeof(planes));
        out.write((char *)&bitsPerPixel, sizeof(bitsPerPixel));
        out.write((char *)&compression, sizeof(compression));
        out.write((char *)&imageSize, sizeof(imageSize));
        out.write((char *)&xPixelsPerMeter, sizeof(xPixelsPerMeter));
        out.write((char *)&yPixelsPerMeter, sizeof(yPixelsPerMeter));
        out.write((char *)&totalColors, sizeof(totalColors));
        out.write((char *)&importantColors, sizeof(importantColors));

        // pixel data, row by row
        for (int i = height - 1; i >= 0; i--)
        {
            for (int j = 0; j < width; j++)
            {
                const color::Color &c = data[i * width + j];
                out.put(c.getB());
                out.put(c.getG());
                out.put(c.getR());
            }
            for (int j = 0; j < (4 - (width * 3) % 4) % 4; j++) // |3| pad the end of each row to a multiple of 4 bytes
            {
                out.put(0);
            }
        }

        out.close();
    }

    // some global default variables, to avoid passing them afloor
    // Framebuffer framebuffer(1920, 1080);
    color::Color clearColor(0, 0, 0);
    color::Color currentColor(255, 255, 255);
}

// notes:
// |1| std::fill fills a range of elements in a container with a given value
// |2| data is a vector of Color, so it is a vector of colors,
// and it is initialized with a vector of size width * height, filled with clearColor
// this is a constructor initialization list, it is used to initialize member variables of a class
// |3| this enhance the image processing, cause multiple hardware graphics accelerators works most efficiently on data aligned to a multiple of 4 bytes.
// so in the code, we pad the end of each row to a multiple of 4 bytes in length if necessary.
// the expression (4 - (width * 3) % 4) % 4  calculates the number of bytes needed to pad the row to a multiple of 4 bytes