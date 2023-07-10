// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>

#include "RasterizerConfig.h"
#include "MathFunctions.h"
#include "gl.h"

void render();

int main(int argc, char *argv[])
{
    /**
     *  if (argc < 2)
        {
        // report version
        std::cout << argv[0] << " Version " << Rasterizer_VERSION_MAJOR << "."
                  << Rasterizer_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
        }
    */

    render();
    return 0;
}

void render()
{
    const int WIDTH = 640;
    const int HEIGHT = 480;

    gl::Color pink(255, 0, 255);
    gl::Framebuffer fb(1920, 1080);

    fb.setClearColor(pink);
    fb.clear();
    fb.renderBuffer();
}