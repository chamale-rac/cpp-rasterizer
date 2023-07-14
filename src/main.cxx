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
        return 1;
    }

    render();
    return 0;
}

void render()
{
    // buffer declaration
    const int WIDTH = 800;
    const int HEIGHT = 600;
    gl::Framebuffer fb(WIDTH, HEIGHT);

    // colors declaration
    gl::Color WHITE(255, 255, 255);
    gl::Color BLACK(0, 0, 0);
    gl::Color PINK(255, 0, 255);

    // polygon declaration
    std::vector<gl::Pixel> star = {
        gl::Pixel(400, 100), // Point 1
        gl::Pixel(475, 225), // Point 2
        gl::Pixel(750, 275), // Point 3
        gl::Pixel(525, 375), // Point 4
        gl::Pixel(600, 600), // Point 5
        gl::Pixel(400, 475), // Point 6
        gl::Pixel(200, 600), // Point 7
        gl::Pixel(275, 375), // Point 8
        gl::Pixel(50, 275),  // Point 9
        gl::Pixel(325, 225)  // Point 10
    };

    // drawing commands
    fb.setClearColor(BLACK);
    fb.clear();

    fb.setCurrentColor(PINK);
    draw::fillPolygon(fb, star);

    fb.setCurrentColor(WHITE);
    draw::polygon(fb, star);

    fb.renderBuffer();
}
