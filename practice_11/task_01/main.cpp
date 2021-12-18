#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/display-table-of-food-orders-in-a-restaurant

class Solution
{
public:
    vector <vector <string>> displayTable(vector <vector <string>>& orders)
    {
        vector <vector <string>> result;

        unordered_map <int, unordered_map <string, int>> data;
        set <string> dishes;

        for (auto i: orders)
        {
            dishes.insert(i[2]);
            data[stoi(i[1])][i[2]]++;
        }

        vector <string> head(dishes.begin(), dishes.end());
        head.insert(head.begin(), "Table");

        result.push_back(head);

        for (const auto& it: data)
        {
            vector <string> row;
            row.push_back(to_string(it.first));
            unordered_map <string, int> map = it.second;
            for (const string& s: dishes)
            {
                row.push_back(to_string(map[s]));
            }

            result.push_back(row);
        }

        sort(result.begin() + 1, result.end(), [](const vector <string>& one, const vector <string>& two)
        {
            return stoi(one[0]) < stoi(two[0]);
        });

        return result;
    }
};

int main()
{
    vector <vector <string>> test = {{"David",  "3", "Ceviche"},
                                     {"Corina", "10", "Beef Burrito"},
                                     {"David", "3", "Fried Chicken"},
                                     {"Carla", "5", "Water"},
                                     {"Carla", "5", "Ceviche"},
                                     {"Rous", "3", "Ceviche"}};

    Solution obj;
    vector <vector <string>> temp = obj.displayTable(test);

    for (const auto& i: temp)
    {
        for (const auto& j: i)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }

    return 0;
}
