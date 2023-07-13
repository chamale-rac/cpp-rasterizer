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
    // buffer declaration
    const int WIDTH = 800;
    const int HEIGHT = 600;
    gl::Framebuffer fb(WIDTH, HEIGHT);

    // colors declaration
    gl::Color WHITE(255, 255, 255);
    gl::Color BLACK(0, 0, 0);
    gl::Color PINK(255, 0, 255);

    // polygon declaration
    std::vector<gl::Pixel> poly_0 = {
        gl::Pixel(165, 380),
        gl::Pixel(185, 360),
        gl::Pixel(180, 330),
        gl::Pixel(207, 345),
        gl::Pixel(233, 330),
        gl::Pixel(230, 360),
        gl::Pixel(250, 380),
        gl::Pixel(220, 385),
        gl::Pixel(205, 410),
        gl::Pixel(193, 383)};

    std::vector<gl::Pixel> poly_1 = {
        gl::Pixel(321, 335),
        gl::Pixel(288, 286),
        gl::Pixel(339, 251),
        gl::Pixel(374, 302)};

    std::vector<gl::Pixel> poly_2 = {
        gl::Pixel(377, 249),
        gl::Pixel(411, 197),
        gl::Pixel(436, 249)};

    std::vector<gl::Pixel> poly_3 = {
        gl::Pixel(413, 177),
        gl::Pixel(448, 159),
        gl::Pixel(502, 88),
        gl::Pixel(553, 53),
        gl::Pixel(535, 36),
        gl::Pixel(676, 37),
        gl::Pixel(660, 52),
        gl::Pixel(750, 145),
        gl::Pixel(761, 179),
        gl::Pixel(672, 192),
        gl::Pixel(659, 214),
        gl::Pixel(615, 214),
        gl::Pixel(632, 230),
        gl::Pixel(580, 230),
        gl::Pixel(597, 215),
        gl::Pixel(552, 214),
        gl::Pixel(517, 144),
        gl::Pixel(466, 180)};

    std::vector<gl::Pixel> poly_4 = {
        gl::Pixel(682, 175),
        gl::Pixel(708, 120),
        gl::Pixel(735, 148),
        gl::Pixel(739, 170)};

    // drawing commands
    fb.setClearColor(BLACK);
    fb.clear();

    fb.setCurrentColor(PINK);
    draw::fillPolygon(fb, poly_0);
    draw::fillPolygon(fb, poly_1);
    draw::fillPolygon(fb, poly_2);
    draw::fillPolygon(fb, poly_3);

    fb.setCurrentColor(WHITE);
    draw::polygon(fb, poly_0);
    draw::polygon(fb, poly_1);
    draw::polygon(fb, poly_2);
    draw::polygon(fb, poly_3);
    draw::polygon(fb, poly_4);

    fb.setCurrentColor(BLACK);
    draw::fillPolygon(fb, poly_4);

    gl::Pixel p0(0, 0);
    gl::Pixel p1(799, 599);

    draw::line(fb, p0, p0);
    // ex:

    fb.renderBuffer();
}