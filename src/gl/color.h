// date: 10/07/2023
// author: samuel chamalé

#pragma once

namespace color
{
    class Color
    {
    public:
        Color();
        Color(unsigned char r, unsigned char g, unsigned char b); // |1|
        unsigned char getR() const;
        unsigned char getG() const;
        unsigned char getB() const;
        void setR(unsigned char r);
        void setG(unsigned char g);
        void setB(unsigned char b);

    private:
        unsigned char r, g, b;
    };
}

// reminders:
// |1| an unsigned char is a data type that represents and integer value between 0 and 255, just perfect!