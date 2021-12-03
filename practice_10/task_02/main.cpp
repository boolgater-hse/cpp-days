#include <iostream>
#include <vector>

using namespace std;

// https://www.hackerrank.com/challenges/vector-erase/problem

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

    int target;
    cin >> target;
    a.erase(a.begin() + (target - 1));

    int start, finish;
    cin >> start >> finish;
    a.erase(a.begin() + (start - 1), a.begin() + (finish - 1));

    cout << a.size() << '\n';
    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i] << ' ';
    }

    return 0;
}
