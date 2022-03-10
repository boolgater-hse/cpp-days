#include "Graph.hpp"

Node::Node(std::string _key, int _val)
{
    key = _key;
    val = _val;
}

Graph::Node::Node(const std::string& key, const int val)
{
    this->key = key;
    this->val = val;
}

int Graph::Node::getVal() const
{
    return this->val;
}

void Graph::Node::setVal(const int other)
{
    this->val = other;
}

std::string Graph::Node::getKey() const
{
    return this->key;
}

void Graph::Node::append(Graph::Node*& other)
{
    edges.insert(other);
}

bool Graph::Node::cmp::operator()(Graph::Node* a, Graph::Node* b) const
{
    return a->getVal() < b->getVal();
}

void Graph::dfsService(Graph::Node* traveler, std::vector <Node*>& visited, std::vector <int>& log)
{
    log.push_back(traveler->getVal());
    visited.push_back(traveler);

    bool flag;
    for (auto i = traveler->edges.begin(); i != traveler->edges.end(); ++i)
    {
        flag = false;
        for (auto j = visited.begin(); j != visited.end(); ++j)
        {
            if ((*i) == (*j))
            {
                flag = true;
                break;
            }
        }

        if (!flag)
        {
            dfsService((*i), visited, log);
        }
    }
}

Graph::Graph()
{
}

Graph::Graph(const NODE& other)
{
    Node* temp = new Node(other.key, other.val);
    data.insert({other.key, temp});
}

Graph::~Graph()
{
    for (auto it = this->data.begin(); it != this->data.end(); ++it)
    {
        delete (*it).second;
    }
}

void Graph::vertex(const NODE& other)
{
    Node* temp = new Node(other.key, other.val);
    data.insert({other.key, temp});
}

void Graph::edge(const NODE& from, const NODE& to)
{
    typedef std::multimap <std::string, Node*>::iterator tempIterator;

    Node* dep = nullptr;
    Node* dest = nullptr;

    std::pair <tempIterator, tempIterator> resultDep = data.equal_range(from.key);
    for (auto it = resultDep.first; it != resultDep.second; ++it)
    {
        if (it->second->getVal() == from.val)
        {
            dep = it->second;
            break;
        }
    }

    std::pair <tempIterator, tempIterator> resultDest = data.equal_range(to.key);
    for (auto it = resultDest.first; it != resultDest.second; ++it)
    {
        if (it->second->getVal() == to.val)
        {
            dest = it->second;
            break;
        }
    }

    if (dep == nullptr || dest == nullptr)
    {
        return;
    }

    dep->append(dest);
    dest->append(dep);
}

std::vector <int> Graph::dfs(const NODE& other)
{
    Node* traveler = nullptr;

    typedef std::multimap <std::string, Node*>::iterator tempIterator;

    std::pair <tempIterator, tempIterator> result = data.equal_range(other.key);
    for (auto it = result.first; it != result.second; ++it)
    {
        if (it->second->getVal() == other.val)
        {
            traveler = it->second;
            break;
        }
    }

    if (traveler == nullptr)
    {
        return {};
    }

    std::vector <Node*> visited;
    std::vector <int> log;
    dfsService(traveler, visited, log);

    return log;
}

std::vector <int> Graph::bfs(const NODE& other)
{
    Node* traveler = nullptr;

    typedef std::multimap <std::string, Node*>::iterator tempIterator;

    std::pair <tempIterator, tempIterator> result = data.equal_range(other.key);
    for (auto it = result.first; it != result.second; ++it)
    {
        if (it->second->getVal() == other.val && it->second->getKey() == other.key)
        {
            traveler = it->second;
            break;
        }
    }

    if (traveler == nullptr)
    {
        return {};
    }

    std::queue <Node*> q;
    std::vector <Node*> visited;
    std::vector <int> log;
    q.push(traveler);
    visited.push_back(traveler);
    while (!q.empty())
    {
        traveler = q.front();
        log.push_back(traveler->getVal());

        bool flag;
        for (auto i = traveler->edges.begin(); i != traveler->edges.end(); ++i)
        {
            flag = false;
            for (auto j = visited.begin(); j != visited.end(); ++j)
            {
                if ((*i) == (*j))
                {
                    flag = true;
                    break;
                }
            }

            if (!flag)
            {
                q.push((*i));
                visited.push_back((*i));
            }
        }

        q.pop();
    }

    return log;
}

std::vector <int> Graph::search(const std::string& key)
{
    std::vector <int> out;

    typedef std::multimap <std::string, Node*>::iterator tempIterator;

    std::pair <tempIterator, tempIterator> result = data.equal_range(key);
    for (auto it = result.first; it != result.second; ++it)
    {
        out.push_back(it->second->getVal());
    }

    return out;
}
