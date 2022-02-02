#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/

class Solution {
public:
    int mostWordsFound(vector<string>& sentences)
    {
        int result = 0;

        for (auto s: sentences)
        {
            stringstream ss;
            ss << s;

            int count = 0;
            while (!ss.eof())
            {
                string temp;
                ss >> temp;
                count++;
            }
            result = max(result, count);
        }

        return result;
    }
};

int main()
{
    vector <string> a = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};

    Solution obj;
    cout << obj.mostWordsFound(a);

    return 0;
}
