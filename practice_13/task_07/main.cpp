#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/create-target-array-in-the-given-order/

class Solution
{
public:
    vector <int> createTargetArray(vector <int>& nums, vector <int>& index)
    {
        vector <int> target;

        for (int i = 0; i < nums.size(); i++)
        {
            target.insert(target.begin() + index[i], nums[i]);
        }

        return target;
    }
};

int main()
{
    vector <int> a = {0, 1, 2, 3, 4};
    vector <int> b = {0, 1, 2, 2, 1};

    Solution obj;
    vector <int> out = obj.createTargetArray(a, b);

    return 0;
}
