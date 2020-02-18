/*
 * @lc app=leetcode.cn id=940 lang=cpp
 *
 * [940] 不同的子序列 II
 */

// @lc code=start
class Solution {
public:
    int distinctSubseqII(string S) {
        long result, mod = 1e9 + 7;
        long endWith[26] = {};
        for(char c : S)
            endWith[c - 'a'] = accumulate(begin(endWith), end(endWith), 1L) % mod;
        result = accumulate(begin(endWith), end(endWith), 0L) % mod;
        return result ;
    }
};
// @lc code=end

