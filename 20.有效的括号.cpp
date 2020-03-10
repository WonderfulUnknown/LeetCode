/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        if (!s.size())
            return true;
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if (st.empty())
                    return false;
                if ((st.top() == '(' && s[i] == ')') ||
                    (st.top() == '{' && s[i] == '}') ||
                    (st.top() == '[' && s[i] == ']'))
                    st.pop();
                else
                    return false;
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};
// @lc code=end
