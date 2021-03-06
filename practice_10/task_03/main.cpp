#include <iostream>
#include <deque>

using namespace std;

// https://www.hackerrank.com/challenges/deque-stl/problem

void printKMax(int arr[], int n, int k)
{
    deque <int> deq;
    for (int i = 0; i < n; ++i)
    {
        if (!deq.empty() && deq.front() == i - k)
        {
            deq.pop_front();
        }
        while (!deq.empty() && arr[deq.back()] < arr[i])
        {
            deq.pop_back();
        }
        deq.push_back(i);
        if (i >= k - 1)
        {
            cout << arr[deq.front()] << ' ';
        }
    }
    cout << endl;
}

int main()
{

    int t;
    cin >> t;
    while (t > 0)
    {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        printKMax(arr, n, k);
        t--;
    }

    return 0;
}
