// date: 10/07/2023
// author: samuel chamalé

#include "color.h"

namespace color
{
    Color::Color() : r(0), g(0), b(0) {} // default constructor

    Color::Color(unsigned char r, unsigned char g, unsigned char b) : r(r), g(g), b(b) {}

    unsigned char Color::getR() const { return r; }

    unsigned char Color::getG() const { return g; }

    unsigned char Color::getB() const { return b; }

    void Color::setR(unsigned char r) { this->r = r; }

    void Color::setG(unsigned char g) { this->g = g; }

    void Color::setB(unsigned char b) { this->b = b; }
}