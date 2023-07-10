// date: 10/07/2023
// author: samuel chamalé

#include "color.h"

namespace color
{
    Color::Color() : r(0), g(0), b(0) {} // default constructor

    Color::Color(unsigned char r, unsigned char g, unsigned char b)
        : r(clamp(r)), g(clamp(g)), b(clamp(b)) {}

    unsigned char Color::getR() const { return r; }

    unsigned char Color::getG() const { return g; }

    unsigned char Color::getB() const { return b; }

    void Color::setR(unsigned char r) { this->r = clamp(r); } // |1|

    void Color::setG(unsigned char g) { this->g = clamp(g); }

    void Color::setB(unsigned char b) { this->b = clamp(b); }

    unsigned char Color::clamp(unsigned char value)
    {
        return (value > 255) ? 255 : ((value < 0) ? 0 : value); // |2| more about ternary operator
    }
}

// notes:
// |1| it may looks like clamp function is not necessary, but even we are using unsigned char
// it is possible to set a value greater than 255 or less than 0, so we need to clamp it.
// without clamping if we pass a value greater than 255 it will wrap around an start from 0 and so on.
// |2| link: https://en.cppreference.com/w/cpp/language/operator_other
