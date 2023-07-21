// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>

#include "RasterizerConfig.h"
#include "gl.h"
#include "draw.h"

void render();
void fillAnyPolygon();

int main(int argc, char *argv[])
{
    render();
    fillAnyPolygon();
    return 0;
}

void render()
{
    /* PERSONAL DRAW FOR REPO SHOW OFF */

    // buffer configuration
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

    std::string fileName = "showOff.bmp";
    fb.renderBuffer(fileName);

    std::cout << "File " << fileName << " created." << std::endl;
}

void fillAnyPolygon()
{
    /* DRAW FOR 'Lab 1: Filling any Polygon' */

    // buffer configuration
    const int WIDTH = 1080;
    const int HEIGHT = 1080;
    gl::Framebuffer fb(WIDTH, HEIGHT);

    // colors declaration
    // color palette: https://colorhunt.co/palette/331d2c3f2e3ea78295efe1d1
    gl::Color HEX_331D2C(51, 29, 44);
    gl::Color HEX_3F2E3E(63, 46, 62);
    gl::Color HEX_A78295(167, 130, 149);
    gl::Color HEX_EFE1D1(239, 225, 209);
    gl::Color HEX_313638(48, 51, 56); // black alternative

    // polygon declaration
    std::vector<gl::Pixel>
        POLYGON1 = {
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

    std::vector<gl::Pixel> POLYGON2 = {
        gl::Pixel(321, 335),
        gl::Pixel(288, 286),
        gl::Pixel(339, 251),
        gl::Pixel(374, 302)};

    std::vector<gl::Pixel> POLYGON3 = {
        gl::Pixel(377, 249),
        gl::Pixel(411, 197),
        gl::Pixel(436, 249)};

    std::vector<gl::Pixel> POLYGON4 = {
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

    std::vector<gl::Pixel> POLYGON5 = {
        gl::Pixel(682, 175),
        gl::Pixel(708, 120),
        gl::Pixel(735, 148),
        gl::Pixel(739, 170)};

    // drawing commands
    fb.setClearColor(HEX_313638);
    fb.clear();

    fb.setCurrentColor(HEX_331D2C);
    draw::fillPolygon(fb, POLYGON1);
    draw::polygon(fb, POLYGON1);

    fb.setCurrentColor(HEX_3F2E3E);
    draw::fillPolygon(fb, POLYGON2);
    draw::polygon(fb, POLYGON2);

    fb.setCurrentColor(HEX_A78295);
    draw::fillPolygon(fb, POLYGON3);
    draw::polygon(fb, POLYGON3);

    fb.setCurrentColor(HEX_EFE1D1);
    draw::fillPolygon(fb, POLYGON4);
    draw::polygon(fb, POLYGON4);

    fb.setCurrentColor(HEX_331D2C);
    draw::fillPolygon(fb, POLYGON5);
    draw::polygon(fb, POLYGON5);

    std::string fileName = "fillAnyPolygon.bmp";
    fb.renderBuffer(fileName);

    std::cout << "File " << fileName << " created." << std::endl;
}
