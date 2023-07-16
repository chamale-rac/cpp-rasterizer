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
    render();
    return 0;
}

void render()
{
    // buffer declaration
    const int WIDTH = 450;
    const int HEIGHT = 450;
    gl::Framebuffer fb(WIDTH, HEIGHT);

    // colors declaration
    gl::Color WHITE(248, 247, 252);
    gl::Color BLACK(18, 17, 22);

    gl::Color GREEN(13, 185, 52);
    gl::Color BROWN(170, 122, 84);

    gl::Color SKIN(247, 196, 166);

    // polygon declaration
    std::vector<gl::Pixel>
        HAND = {
            gl::Pixel(110, 287),
            gl::Pixel(150, 259),
            gl::Pixel(176, 252), // intersection with oil
            gl::Pixel(233, 242),
            gl::Pixel(241, 248),
            gl::Pixel(239, 260),
            gl::Pixel(207, 273),
            gl::Pixel(254, 277),
            gl::Pixel(302, 254), // intersection with oil
            gl::Pixel(328, 251),
            gl::Pixel(338, 253),
            gl::Pixel(340, 265),
            gl::Pixel(261, 313),
            gl::Pixel(167, 316),
            gl::Pixel(127, 344)};

    std::vector<gl::Pixel> OIL = {
        gl::Pixel(174, 275),
        gl::Pixel(176, 252), // hand intersection
        gl::Pixel(209, 231),
        gl::Pixel(233, 225),
        gl::Pixel(244, 228),
        gl::Pixel(275, 238),
        gl::Pixel(302, 254), // hand intersection
        gl::Pixel(304, 280)};

    std::vector<gl::Pixel> TRUNK = {
        gl::Pixel(235, 227), // hand intersection
        gl::Pixel(237, 135),
        gl::Pixel(238, 137),
        gl::Pixel(241, 144),
        gl::Pixel(240, 227), // hand intersection
    };

    std::vector<gl::Pixel> LEFT_LEAVE = {
        gl::Pixel(237, 172),
        gl::Pixel(216, 160),
        gl::Pixel(207, 135),
        gl::Pixel(225, 147)};

    std::vector<gl::Pixel> RIGHT_LEAVE = {
        gl::Pixel(240, 192),
        gl::Pixel(256, 165),
        gl::Pixel(280, 154),
        gl::Pixel(265, 183)};

    std::vector<gl::Pixel> TOP_LEAVE = {
        gl::Pixel(238, 147),
        gl::Pixel(249, 119),
        gl::Pixel(264, 108),
        gl::Pixel(256, 132)};

    // drawing commands
    fb.setClearColor(WHITE);
    fb.clear();

    fb.setCurrentColor(GREEN);
    draw::fillPolygon(fb, LEFT_LEAVE);
    draw::fillPolygon(fb, RIGHT_LEAVE);
    draw::fillPolygon(fb, TOP_LEAVE);

    fb.setCurrentColor(BLACK);
    draw::polygon(fb, LEFT_LEAVE);
    draw::polygon(fb, RIGHT_LEAVE);
    draw::polygon(fb, TOP_LEAVE);

    draw::fillPolygon(fb, TRUNK);

    fb.setCurrentColor(BROWN);
    draw::fillPolygon(fb, OIL);
    fb.setCurrentColor(BLACK);
    draw::polygon(fb, OIL);

    fb.setCurrentColor(SKIN);
    draw::fillPolygon(fb, HAND);
    fb.setCurrentColor(BLACK);
    draw::polygon(fb, HAND);

    std::string fileName = "first.bmp";
    fb.renderBuffer(fileName);
}
