#include <iostream>
#include <vector>

void equalizeSizeAndCapacity(std::vector <int>& vec)
{
    vec.shrink_to_fit();
}

void removeZeroes(std::vector <int>& vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (vec[i] == 0)
        {
            vec.erase(vec.begin() + i);
            i--;
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
