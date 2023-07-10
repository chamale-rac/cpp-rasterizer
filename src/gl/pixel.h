// date: 10/07/2023
// author: samuel chamalé

#pragma once

namespace pixel
{
    class Pixel
    {
    public:
        int x, y; // TODO: consider making these private and adding getters and setters
        Pixel(int x = 0, int y = 0);
    };
}

// notes:
// |1| i used a class here because i wanted to add some methods to the pixel, in the future, i believe XD