#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// https://www.hackerrank.com/challenges/cpp-lower-bound

int main()
{
    int n;
    cin >> n;

    vector <int> a;
    for (int i = 0; i < n; ++i)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int target;
        cin >> target;

        auto it = lower_bound(a.begin(), a.end(), target);
        if (*it == target)
        {
            cout << "Yes " << (it - a.begin()) + 1 << '\n';
        }
        else
        {
            cout << "No " << (it - a.begin()) + 1 << '\n';
        }
    }

    return 0;
}
