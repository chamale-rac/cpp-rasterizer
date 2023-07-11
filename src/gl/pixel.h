// date: 10/07/2023
// author: samuel chamalé

#pragma once

namespace pixel
{
    class Pixel
    {
    public:
        double x, y;
        Pixel();
        Pixel(double x, double y);
    };
}
// notes:
// |1| i used a class here because i wanted to add some methods to the pixel, in the future, i believe XD