#include <iostream>
#include <vector>
#include <algorithm>

bool isPalindrome(std::string& s)
{
    using StringIterator = std::string::iterator;
    using RevStringIterator = std::string::reverse_iterator;

    StringIterator front;
    RevStringIterator back;
    for (front = s.begin(), back = s.rbegin(); front != s.begin() + (s.size() / 2); front++, back++)
    {
        if (*front != *back)
        {
            return false;
        }
    }

    return true;
}

std::string sortByLengthWithSort(std::string s)
{
    using VectorIterator = std::vector <std::string>::iterator;

    std::vector <std::string> temp;
    s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());

    std::string delimeter = " ";
    size_t pos = 0;
    std::string token;
    while (pos != std::string::npos)
    {
        pos = s.find(delimeter);
        token = s.substr(0, pos);
        if (token.empty())
        {
            s.erase(0, pos + delimeter.size());
        }
        else
        {
            temp.push_back(token);
            s.erase(0, pos + delimeter.size());
        }
    }

//  Bubble sort
    for (VectorIterator i = temp.begin(); i != temp.end(); ++i)
    {
        for (VectorIterator j = temp.begin(); j < i; ++j)
        {
            if (i->size() < j->size())
            {
                std::swap(*i, *j);
            }
        }
    }

//  Or use Quick sort in std::sort from <algorithm>
//    std::sort(temp.begin(), temp.end(), [](const std::string& one, const std::string& two)
//    {
//        return one.size() < two.size();
//    });

    std::string result;
    for (VectorIterator it = temp.begin(); it != temp.end(); ++it)
    {
        if (it != temp.end() - 1)
        {
            result += *it + ' ';
        }
        else
        {
            result += *it;
        }
    }

    return result;
}

int main()
{
    std::string s;
    std::getline(std::cin >> std::ws, s);
    std::cout << "Initial string: " << s << '\n';
    std::cout << "Is palindrome: " << (isPalindrome(s) ? "True" : "False") << '\n';
    std::cout << std::endl;

    std::string test_string = "C++ is a very      performant language.\n";
    std::cout << "Initial string: " << test_string << '\n';
    std::cout << "Sorted: " << sortByLengthWithSort(test_string);
    std::cout << std::endl;

    return 0;
}
