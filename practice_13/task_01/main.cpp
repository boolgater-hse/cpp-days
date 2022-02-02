#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>

// 10
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10

std::vector <double> runningMedian(std::vector <int> a)
{
    std::vector <double> result;

    std::priority_queue <int, std::vector <int>, std::greater <int>> qMin;
    std::priority_queue <int> qMax;

    double median = 0;

    for (int i: a)
    {
        if (i <= median)
        {
            qMax.push(i);
        }
        else
        {
            qMin.push(i);
        }

        if (qMin.size() > qMax.size() + 1)
        {
            qMax.push(qMin.top());
            qMin.pop();
        }
        if (qMax.size() > qMin.size() + 1)
        {
            qMin.push(qMax.top());
            qMax.pop();
        }

        if (qMin.size() == qMax.size())
        {
            median = (double) (qMax.top() + qMin.top()) / 2;
        }
        else if (qMin.size() > qMax.size())
        {
            median = (double) qMin.top();
        }
        else if (qMin.size() < qMax.size())
        {
            median = (double) qMax.top();
        }

        result.push_back(median);
    }

    return result;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector <int> a;

    while (n--)
    {
        int temp;
        std::cin >> temp;
        a.push_back(temp);
    }

    std::vector <double> result = runningMedian(a);

    for (double i: result)
    {
        std::cout << std::fixed << std::setprecision(1) << i << '\n';
    }

    return 0;
}
