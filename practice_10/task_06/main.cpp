#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// https://www.hackerrank.com/challenges/components-in-graph/problem

int findSet(int x, vector <int>& r)
{
    if (r[x] == x)
    {
        return x;
    }
    else
    {
        return findSet(r[x], r);
    }
}

int main()
{
    int n;
    cin >> n;

    vector <int> root(2 * n + 1);
    vector <int> count(2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i)
    {
        root[i] = i;
        count[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        int g, b;
        cin >> g >> b;

        int rg = findSet(g, root);
        int rb = findSet(b, root);

        if (rg == rb)
        {
            continue;
        }

        root[rb] = rg;
        count[rg] += count[rb];
        count[rb] = 0;
    }

    int mn = 2 * n + 1;
    int mx = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (count[i] > 1 && count[i] < mn)
        {
            mn = count[i];
        }
        if (count[i] > mx)
        {
            mx = count[i];
        }
    }
    cout << mn << " " << mx;

    return 0;
}
