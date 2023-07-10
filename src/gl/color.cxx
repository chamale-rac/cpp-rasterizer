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

    void Color::setR(unsigned char r) { this->r = clamp(r); } // |1| clamping

    void Color::setG(unsigned char g) { this->g = clamp(g); }

    void Color::setB(unsigned char b) { this->b = clamp(b); }

    unsigned char Color::clamp(unsigned char value)
    {
        return (value > 255) ? 255 : ((value < 0) ? 0 : value); // |2| more about ternary operator
    }

    std::ostream &operator<<(std::ostream &os, const Color &c)
    {
        os << "Color(" << static_cast<int>(c.r) << ", "
           << static_cast<int>(c.g) << ", "
           << static_cast<int>(c.b) << ")";
        return os;
    } // |3| reminder -> how to print a color object

    Color operator+(const Color &lhs, const Color &rhs) // reminder -> lhs: left hand side, rhs: right hand side
    {
        unsigned char r = lhs.r + rhs.r;
        unsigned char g = lhs.g + rhs.g;
        unsigned char b = lhs.b + rhs.b;
        return Color(r, g, b);
    }

    Color operator*(const Color &c, float f)
    {
        unsigned char r = static_cast<unsigned char>(c.r * f);
        unsigned char g = static_cast<unsigned char>(c.g * f);
        unsigned char b = static_cast<unsigned char>(c.b * f);
        return Color(r, g, b);
    }

    Color operator*(float f, const Color &c)
    {
        return c * f; // we have already defined c * f, so we can use it here, cool!
    }
}

// notes:
// |1| it may looks like clamp function is not necessary, but even we are using unsigned char
// it is possible to set a value greater than 255 or less than 0, so we need to clamp it.
// without clamping if we pass a value greater than 255 it will wrap around an start from 0 and so on.
// |2| reference: https://en.cppreference.com/w/cpp/language/operator_other
// |3| this cool cast make possible to print the color object in a custom format using standard output stream.
// ex: color::Color red(255, 0, 0); std::cout << "Red: " << red << std::endl;
// result: Red: Color(255, 0, 0)
// reference: https://cplusplus.com/forum/beginner/198631/
