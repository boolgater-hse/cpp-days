#ifndef PRACTICE_12_GRAPH_HPP
#define PRACTICE_12_GRAPH_HPP


#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <memory>

typedef struct Node
{
    std::string key;
    int val;

    Node(std::string _key, int _val);
} NODE;

class Graph
{
private:
    class Node
    {
    private:
        std::string key;
        int val;
    public:
        Node(const std::string& key, int val);

        int getVal() const;

        void setVal(int other);

        std::string getKey() const;

        void append(std::shared_ptr <Node>& other);

        struct cmp
        {
            bool operator()(std::shared_ptr <Node> a, std::shared_ptr <Node> b) const;
        };

        std::multiset <std::shared_ptr <Node>, cmp> edges;
    };

    std::multimap <std::string, std::shared_ptr <Node>> data;

    void dfsService(const std::shared_ptr <Node>& traveler, std::vector <std::shared_ptr <Node>>& visited,
                    std::vector <int>& log);

public:
    Graph();

    Graph(const NODE& other);

    ~Graph();

    void vertex(const NODE& other);

    void edge(const NODE& from, const NODE& to);

    std::vector <int> dfs(const NODE& other);

    std::vector <int> bfs(const NODE& other);

    std::vector <int> search(const std::string& key);
};


#endif //PRACTICE_12_GRAPH_HPP
