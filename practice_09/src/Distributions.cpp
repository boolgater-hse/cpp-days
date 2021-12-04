#include <iostream>
#include <chrono>
#include <random>
#include "Distributions.hpp"

#define POINT 15000

std::vector <int> runGaltonBoard(double shift, int width, int height, int amount)
{
    std::mt19937 engine(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution <int> distance(0, 1);

    std::vector <int> board(amount);
    for (int iter = 0; iter < POINT; ++iter)
    {
        double point = amount / 2;

        for (int i = 0; i < height; ++i)
        {
            int side = distance(engine);
            if (side == 0)
            {
                point += shift;
            }
            else
            {
                point -= shift;
            }
            if (point < 0)
            {
                point += shift;
            }
            else if (point > amount - 1)
            {
                point -= shift;
            }
        }
        board[(int) point] += 1;
    }

    return board;
}
