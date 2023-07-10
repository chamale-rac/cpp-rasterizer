// date: 10/07/2023
// author: samuel chamalé

#pragma once
#include <iostream>

namespace color
{
    class Color
    {
    public:
        Color();
        Color(unsigned char r, unsigned char g, unsigned char b); // |1| unsigned chars
        unsigned char getR() const;
        unsigned char getG() const;
        unsigned char getB() const;
        void setR(unsigned char r);
        void setG(unsigned char g);
        void setB(unsigned char b);
        friend std::ostream &operator<<(std::ostream &os, const Color &c); // |2| friend keyword

    private:
        unsigned char clamp(unsigned char value);
        unsigned char r, g, b;
    };
}

// notes:
// |1| an unsigned char is a data type that represents and integer value between 0 and 255, just perfect!
// |2| friend is a keyword that allows a function or class to access private members of another class.
// it can access the private and protected members of the class as if they were its own members.