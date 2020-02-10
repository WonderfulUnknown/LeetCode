/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long result = 0, temp = abs(long(x));
        while(temp)
        {
            result = result * 10 + temp % 10;
            temp /= 10;
        }
        result = (x > 0) ? result : -result; 
        if(result > INT_MAX || result < INT_MIN)
            return 0;
        return (int)result;
    }
};
// @lc code=end

