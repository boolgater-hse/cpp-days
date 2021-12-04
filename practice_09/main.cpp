#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <map>
#include "VectorTest.hpp"
#include "MyLinkedListTest.hpp"
#include "Distributions.hpp"

int main()
{
    Vector_TestSuite();
    std::cout << std::endl;
    MyLinkedList_TestSuite();
    std::cout << std::endl;

    std::cout << "Galton board:" << '\n';
    std::vector <int> resultGalton;
    resultGalton = runGaltonBoard(0.5, -1, 14, 15);
    for (int i: resultGalton)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    std::cout << "Height: " << resultGalton.size() << '\n';
    std::cout << "Max "
              << std::distance(resultGalton.begin(), std::max_element(resultGalton.begin(), resultGalton.end()))
              << " at " << resultGalton[std::distance(resultGalton.begin(),
                                                      std::max_element(resultGalton.begin(), resultGalton.end()))]
              << '\n';
    std::cout << "Min at "
              << std::distance(resultGalton.begin(), std::min_element(resultGalton.begin(), resultGalton.end()))
              << " equal "
              << resultGalton[std::distance(resultGalton.begin(),
                                            std::min_element(resultGalton.begin(), resultGalton.end()))] << "\n\n";

    std::cout << "std::normal_distribution board:" << '\n';

    std::random_device rd{};
    std::mt19937 gen{rd()};
    std::normal_distribution <> d{5, 2};
    std::map <int, int> resultNormal;

    for (int iter = 0; iter < 15000; ++iter)
    {
        resultNormal[std::round(d(gen))]++;
    }
    for (auto i: resultNormal)
    {
        std::cout << i.second << ' ';
    }
    std::cout << '\n';
    std::cout << "Height: " << resultNormal.size() << '\n';

    return 0;
}
