#include <iostream>
#include <vector>
#include <queue>

// https://www.hackerrank.com/challenges/bfsshortreach

const int INF = 100000000;

std::vector <int> dijkstra(std::vector <std::vector <int>> g, int start)
{
    std::vector <int> d(g.size(), INF);
    d[start] = 0;

    std::priority_queue <int, std::vector <int>, std::greater <int>> q;
    q.push(start);

    while (!q.empty())
    {
        int current = q.top();
        q.pop();

        for (int i = 0; i < g[current].size(); ++i)
        {
            if (d[i] > d[current] + g[current][i])
            {
                d[i] = d[current] + g[current][i];
                q.push(i);
            }
        }
    }

    return d;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n, m;
        std::cin >> n >> m;
        std::vector <std::vector <int>> g(n, std::vector <int>(n, INF));

        while (m--)
        {
            int a, b;
            std::cin >> a >> b;
            g[a - 1][b - 1] = 6;
            g[b - 1][a - 1] = 6;
        }

        int from;
        std::cin >> from;
        from -= 1;

        std::vector <int> out = dijkstra(g, from);
        for (int i: out)
        {
            if (i != 0)
            {
                if (i == INF)
                {
                    std::cout << -1 << ' ';
                }
                else
                {
                    std::cout << i << ' ';
                }
            }
        }
        std::cout << '\n';
    }
}
