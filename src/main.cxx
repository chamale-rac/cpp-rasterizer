// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>

#include "RasterizerConfig.h"
#include "gl.h"
#include "draw.h"

void render();

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        // report version
        std::cout << argv[0] << " Version " << Rasterizer_VERSION_MAJOR << "."
                  << Rasterizer_VERSION_MINOR << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    render();
    return 0;
}

void render()
{
    const int WIDTH = 640;
    const int HEIGHT = 480;

    gl::Color WHITE(255, 255, 255);
    gl::Color BLACK(0, 0, 0);
    gl::Framebuffer fb(WIDTH, HEIGHT);

    gl::Pixel first(1, 1);
    gl::Pixel second(200, 200);
    gl::Pixel third(300, 150);

    fb.setClearColor(BLACK);
    fb.clear();

    fb.setCurrentColor(WHITE);

    // draw::line(fb, first, second, WHITE);

    // draw::line(fb, first, third, WHITE);

    std::vector<gl::Pixel> vertices = {first, second, third};
    draw::polygon(fb, vertices, WHITE);

    fb.renderBuffer();
}