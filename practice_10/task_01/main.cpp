#include <iostream>
#include <vector>

using namespace std;

// https://www.hackerrank.com/challenges/array-left-rotation/problem

vector <int> rotateLeft(int d, vector <int> arr)
{
    for (int i = 0; i < d; ++i)
    {
        int element = arr[0];
        arr.erase(arr.begin());
        arr.push_back(element);
    }

    return arr;
}

int main()
{
    int n;
    int d;
    cin >> n >> d;

    vector <int> arr(n);

    for (int i = 0; i < n; i++)
    {
        int arr_item;
        cin >> arr_item;
        arr[i] = arr_item;
    }

    vector <int> result = rotateLeft(d, arr);

    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];

        if (i != result.size() - 1)
        {
            cout << " ";
        }
    }

    cout << "\n";

    return 0;
}
