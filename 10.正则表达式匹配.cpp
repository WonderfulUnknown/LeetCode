/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        //avoid when p = x*,index = -1
        s = " " + s;
        p = " " + p;
        int m = s.size(), n = p.size();
        bool dp[m + 1][n + 1];
        memset(dp, false, (m + 1) * (n + 1));
        dp[0][0] = true;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == p[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    if (p[j - 1] == '.')
                        dp[i][j] = dp[i - 1][j - 1];
                    else if (p[j - 1] == '*')
                    {
                        //need to judge before string if match
                        if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
                        {
                            dp[i][j] = dp[i - 1][j] //many char match
                                    //|| dp[i][j - 1] //single char match
                                    || dp[i][j - 2];//don't match
                        }
                        // if (p[j - 1] != s[i])//x* stand for null
                        else
                            dp[i][j] = dp[i][j - 2];
                    }
                }            
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

