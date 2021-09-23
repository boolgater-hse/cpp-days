#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

unsigned int getFactorial(unsigned int n)
{
    int temp = 1;

    for (int i = 1; i <= n; ++i)
    {
        temp *= i;
    }

    return temp;
}

vector <string> getRoots(double a, double b, double c)
{
    double d = b * b - 4 * a * c;
    if (a > 0)
    {
        if (d > 0)
        {
            double x1 = ((-b) + sqrt(d)) / (2 * a);
            double x2 = ((-b) - sqrt(d)) / (2 * a);
            return {to_string(x1), to_string(x2)};
        }
        if (d == 0)
        {
            double x1 = -(b / (2 * a));
            return {to_string(x1)};
        }
        if (d < 0)
        {
            double real = -b / (2 * a);
            double imagine = sqrt(-d) / (2 * a);
            string x1 = to_string(real) + '+' + to_string(imagine) + 'i';
            string x2 = to_string(real) + '-' + to_string(imagine) + 'i';
            return {x1, x2};
        }
    }

    return {};
}

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

string getBinary(int n)
{
    string temp;

    while (n > 0)
    {
        if (n % 2 == 0)
        {
            temp += '0';
        }
        else
        {
            temp += '1';
        }
        n /= 2;
    }
    reverse(temp.begin(), temp.end());

    return temp;
}

bool isLatinaAlphabet(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return true;
    }
    return false;
}

int main()
{
    // EX 1
    cout << "Go factorial:" << endl;
    cout << getFactorial(5) << endl;

    // EX 2
    vector <string> good_roots = getRoots(3, 5, -2);
    vector <string> not_so_good_roots = getRoots(1, 6, 14);

    // EX 3
    cout << "Go primes:" << endl;
    for (int i = 1; i < 101; ++i)
    {
        if (isPrime(i))
        {
            cout << i << ' ';
        }
    }
    cout << endl;

    // EX 4
    cout << "Go binary:" << endl;
    cout << getBinary(3443) << endl;

    // EX 5


    // EX 6
    cout << "Go alphabet:" << endl;
    cout << isLatinaAlphabet('a') << isLatinaAlphabet('B') << isLatinaAlphabet('c') << endl;

    return 0;
}
