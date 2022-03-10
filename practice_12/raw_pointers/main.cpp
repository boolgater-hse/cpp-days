#include <iostream>
#include "Graph.hpp"

/*
 * Test case
 *
 * 0, 1, 1, 1, 0, 0, 0, 0,
 * 1, 0, 1, 0, 0, 1, 0, 1,
 * 1, 1, 0, 1, 1, 0, 0, 1,
 * 1, 0, 1, 0, 1, 0, 0, 0,
 * 0, 0, 1, 1, 0, 0, 1, 1,
 * 0, 1, 0, 0, 0, 0, 1, 1,
 * 0, 0, 0, 0, 1, 1, 0, 1,
 * 0, 1, 1, 0, 1, 1, 1, 0,
 *
 */

int main()
{
    Graph obj(Node("alpha", 10));
    Node that("bravo", 20);
    obj.vertex(that);
    obj.vertex(Node("alpha", 30));
    obj.edge(Node("alpha", 10), that);

    obj.vertex(Node("charlie", 40));
    obj.vertex(Node("charlie", 50));
    obj.vertex(Node("charlie", 60));

    Graph g;
    g.vertex(Node("awk", 0));
    g.vertex(Node("awk", 1));
    g.vertex(Node("awk", 2));
    g.vertex(Node("awk", 3));
    g.vertex(Node("awk", 4));
    g.vertex(Node("awk", 5));
    g.vertex(Node("awk", 6));
    g.vertex(Node("awk", 7));

    g.edge(Node("awk", 0), Node("awk", 1));
    g.edge(Node("awk", 0), Node("awk", 2));
    g.edge(Node("awk", 0), Node("awk", 3));

    g.edge(Node("awk", 1), Node("awk", 2));
    g.edge(Node("awk", 1), Node("awk", 5));
    g.edge(Node("awk", 1), Node("awk", 7));

    g.edge(Node("awk", 2), Node("awk", 3));
    g.edge(Node("awk", 2), Node("awk", 4));
    g.edge(Node("awk", 2), Node("awk", 7));

    g.edge(Node("awk", 3), Node("awk", 4));

    g.edge(Node("awk", 4), Node("awk", 6));
    g.edge(Node("awk", 4), Node("awk", 7));

    g.edge(Node("awk", 5), Node("awk", 6));
    g.edge(Node("awk", 5), Node("awk", 7));

    g.edge(Node("awk", 6), Node("awk", 7));

    std::cout << "Search for nodes with key 'charlie':\n";
    std::vector <int> search_log = obj.search("charlie");
    for (int i: search_log)
    {
        std::cout << i << ' ';
    }
    std::cout << "\n\n";

    std::cout << "DFS:\n";
    std::vector <int> dfs_log = g.dfs(Node("awk", 7));
    for (int i: dfs_log)
    {
        std::cout << i << ' ';
    }
    std::cout << "\n\n";

    std::cout << "BFS:\n";
    std::vector <int> bfs_log = g.bfs(Node("awk", 5));
    for (int i: bfs_log)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
