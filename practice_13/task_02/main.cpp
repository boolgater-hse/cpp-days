#include <iostream>
#include <vector>
#include <queue>

// https://www.hackerrank.com/challenges/bfsshortreach

const int INF = 100000000;

std::vector <int> dijkstra(const std::vector <std::vector <std::pair <int, int>>>& g, int start)
{
    std::priority_queue <std::pair <int, int>, std::vector <std::pair <int, int>>, std::greater <std::pair <int, int>>> q;
    std::vector <int> distance(g.size(), INF);

    q.push(std::make_pair(0, start));
    distance[start] = 0;

    while (!q.empty())
    {
        int current = q.top().second;
        q.pop();

        for (auto i = g[current].begin(); i != g[current].end(); ++i)
        {
            int to = (*i).first;
            int weight = (*i).second;

            if (distance[to] > distance[current] + weight)
            {
                distance[to] = distance[current] + weight;
                q.push(std::make_pair(distance[to], to));
            }
        }
    }

    return distance;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n, m;
        std::cin >> n >> m;
        std::vector <std::vector <std::pair <int, int>>> g(n);

        while (m--)
        {
            int a, b;
            std::cin >> a >> b;
            g[a - 1].push_back(std::make_pair(b - 1, 6));
            g[b - 1].push_back(std::make_pair(a - 1, 6));
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
