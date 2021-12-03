#include <iostream>
#include <stack>

using namespace std;

// https://www.hackerrank.com/challenges/balanced-brackets/problem

// I'm sorry for that
string isBalanced(string s)
{
    stack <char> st;

    for (char i: s)
    {
        if (i == '{' || i == '(' || i == '[')
        {
            st.push(i);
            continue;
        }
        if (i == '}' || i == ')' || i == ']')
        {
            if (st.empty())
            {
                return "NO";
            }
            switch (i)
            {
                case '}':
                    if (st.top() == '{')
                    {
                        st.pop();
                    }
                    else
                    {
                        return "NO";
                    }
                    break;
                case ')':
                    if (st.top() == '(')
                    {
                        st.pop();
                    }
                    else
                    {
                        return "NO";
                    }
                    break;
                case ']':
                    if (st.top() == '[')
                    {
                        st.pop();
                    }
                    else
                    {
                        return "NO";
                    }
                    break;
            }
        }
    }
    if (!st.empty())
    {
        return "NO";
    }
    return "YES";
}

int main()
{
    int t;
    cin >> t;

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        cin >> s;

        string result = isBalanced(s);

        cout << result << "\n";
    }

    return 0;
}
