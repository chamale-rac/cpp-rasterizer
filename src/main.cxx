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
    const int WIDTH = 800;
    const int HEIGHT = 600;

    gl::Color WHITE(255, 255, 255);
    gl::Color BLACK(0, 0, 0);
    gl::Framebuffer fb(WIDTH, HEIGHT);

    gl::Pixel first(400, 100);
    gl::Pixel second(100, 500);
    gl::Pixel third(700, 500);

    fb.setClearColor(BLACK);
    fb.clear();

    fb.setCurrentColor(WHITE);

    // draw::line(fb, first, second, WHITE);
    // draw::line(fb, first, third, WHITE);

    // std::vector<gl::Pixel> poly_0 = {
    //     gl::Pixel(165, 380),
    //     gl::Pixel(185, 360),
    //     gl::Pixel(180, 330),
    //     gl::Pixel(207, 345),
    //     gl::Pixel(233, 330),
    //     gl::Pixel(230, 360),
    //     gl::Pixel(250, 380),
    //     gl::Pixel(220, 385),
    //     gl::Pixel(205, 410),
    //     gl::Pixel(193, 383)};

    // std::vector<gl::Pixel> poly_1 = {
    //     gl::Pixel(288, 286),
    //     gl::Pixel(321, 335),
    //     gl::Pixel(339, 251),
    //     gl::Pixel(374, 302)};

    // std::vector<gl::Pixel> poly_2 = {
    //     gl::Pixel(377, 249),
    //     gl::Pixel(411, 197),
    //     gl::Pixel(436, 249)};

    gl::Color RED(255, 0, 0);
    gl::Color GREEN(0, 255, 0);
    gl::Color BLUE(0, 0, 255);

    gl::Pixel p1(400, 100);
    gl::Pixel p2(100, 500);
    gl::Pixel p3(700, 500);

    fb.setCurrentColor(RED);
    // draw::line(fb, p1, p2, WHITE);

    fb.setCurrentColor(GREEN);
    // draw::line(fb, p2, p3, WHITE);

    // draw::line(fb, p3, p1, WHITE);

    gl::Pixel topLeft(1, 1);
    gl::Pixel bottomRight(799, 599);
    gl::Pixel topRight(799, 1);
    gl::Pixel bottomLeft(1, 599);

    fb.setCurrentColor(BLUE);
    draw::line(fb, topLeft, bottomRight, WHITE);

    fb.setCurrentColor(RED);
    draw::line(fb, bottomRight, topRight, WHITE);

    fb.setCurrentColor(GREEN);
    draw::line(fb, topRight, topLeft, WHITE);

    // std::vector<gl::Pixel> poly_3 = {
    //     gl::Pixel(413, 177),
    //     gl::Pixel(448, 159),
    //     gl::Pixel(502, 88),
    //     gl::Pixel(553, 53),
    //     gl::Pixel(535, 36),
    //     gl::Pixel(676, 37),
    //     gl::Pixel(660, 52),
    //     gl::Pixel(750, 145),
    //     gl::Pixel(761, 179),
    //     gl::Pixel(672, 192),
    //     gl::Pixel(659, 214),
    //     gl::Pixel(615, 214),
    //     gl::Pixel(632, 230),
    //     gl::Pixel(580, 230),
    //     gl::Pixel(597, 215),
    //     gl::Pixel(552, 214),
    //     gl::Pixel(517, 144),
    //     gl::Pixel(466, 180)};

    // draw::polygon(fb, poly_2, WHITE);

    fb.renderBuffer();
}