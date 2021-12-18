#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

// https://leetcode.com/problems/employee-importance

using namespace std;

class Employee
{
public:
    int id;
    int importance;
    vector <int> subordinates;
};

class Solution
{
public:
    int getImportance(vector <Employee*> employees, int id)
    {
        unordered_map <int, Employee*> m;
        for (auto i: employees)
        {
            m[i->id] = i;
        }
        int sum = 0;
        queue <Employee*> q;
        q.push(m[id]);
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            for (auto i: p->subordinates)
            {
                q.push(m[i]);
            }
            sum += p->importance;
        }

        return sum;
    }
};

int main()
{

    return 0;
}
