#include <iostream>
#include <vector>

void equalizeSizeAndCapacity(std::vector <int>& vec)
{
    vec.shrink_to_fit();
}

void removeZeroes(std::vector <int>& vec)
{
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        if (*it == 0)
        {
            vec.erase(it);
            it--;
        }
    }
}

void printVector(const std::vector <int>& vec)
{
    for (auto& i: vec)
    {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}
