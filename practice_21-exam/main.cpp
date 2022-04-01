#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <string>

#include "merge_output.hpp"

int main()
{
    const std::vector <std::string> c1 {"delta", "beta", "alpha"};
    const std::list <std::string> c2 {"delta", "beta", "alpha"};
    const std::set <std::string> c3 {"one", "two", "four"};

    std::vector <std::string> d1;
    std::list <std::string> d2;
    std::set <std::string> d3;

    merge(c1, c2, d1);
    output(std::cout, d1) << '\n';
    merge(c2, c3, d2);
    output(std::cout, d2) << '\n';
    merge(c3, c1, d3);
    output(std::cout, d3) << '\n';

    return 0;
}
