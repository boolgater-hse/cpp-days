#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/max-increase-to-keep-city-skyline/

class Solution
{
public:
    int maxIncreaseKeepingSkyline(vector <vector <int>>& grid)
    {
        vector <int> row(grid.size(), 0);
        vector <int> col(grid.size(), 0);

        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid.size(); ++j)
            {
                row[i] = max(row[i], grid[i][j]);
                col[j] = max(col[j], grid[i][j]);
            }
        }

        int result = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid.size(); ++j)
            {
                result += min(row[i], col[j]) - grid[i][j];
            }
        }

        return result;
    }
};

int main()
{
    vector <vector <int>> a = {{3, 0, 8, 4},
                               {2, 4, 5, 7},
                               {9, 2, 6, 3},
                               {0, 3, 1, 0}};

    Solution obj;
    cout << obj.maxIncreaseKeepingSkyline(a);

    return 0;
}
