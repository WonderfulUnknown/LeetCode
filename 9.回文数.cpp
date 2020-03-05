/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0)
            return true;
        if (x < 0)
            return false;

        vector<int> v;
        while (x > 0)
        {
            v.push_back(x % 10);
            x /= 10;
        }

        for (int i = 0, j = v.size() - 1; i < j; i++, j--)
        {
            if (v[i] != v[j])
                return false;
        }
        return true;
    }
};
// @lc code=end

