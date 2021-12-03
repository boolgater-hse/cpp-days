#include <iostream>
#include <vector>

using namespace std;

// https://www.hackerrank.com/challenges/equal-stacks/problem

int equalStacks(vector <int> h1, vector <int> h2, vector <int> h3)
{
    bool equal = false;

    int one = 0;
    for (int i = 0; i < h1.size(); ++i)
    {
        one += h1[i];
    }
    int two = 0;
    for (int i = 0; i < h2.size(); ++i)
    {
        two += h2[i];
    }
    int three = 0;
    for (int i = 0; i < h3.size(); ++i)
    {
        three += h3[i];
    }

    if (one == two && two == three)
    {
        equal = true;
    }

    int ind1 = 0, ind2 = 0, ind3 = 0;
    while (!equal)
    {
        if (one >= two && one >= three)
        {
            one -= h1[ind1];
            ind1++;
        }
        else if (two >= one && two >= three)
        {
            two -= h2[ind2];
            ind2++;
        }
        else if (three >= one && three >= two)
        {
            three -= h3[ind3];
            ind3++;
        }
        if ((one == two && two == three) || (one == 0 && two == 0 && three == 0))
        {
            equal = true;
        }
    }

    return one;
}

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector <int> a1, a2, a3;
    for (int i = 0; i < n1; ++i)
    {
        int temp;
        cin >> temp;
        a1.push_back(temp);
    }
    for (int i = 0; i < n2; ++i)
    {
        int temp;
        cin >> temp;
        a2.push_back(temp);
    }
    for (int i = 0; i < n3; ++i)
    {
        int temp;
        cin >> temp;
        a3.push_back(temp);
    }

    cout << equalStacks(a1, a2, a3);

    return 0;
}
