/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start
class Solution {
public:
    int gcd(int a,int b){
        int temp = a % b;
        if (temp == 0)
            return b;
        else
            return gcd(b,temp);
    }
    
    bool canMeasureWater(int x, int y, int z) {
        // int temp;
        // temp = gcd(x, y);
        if (x + y < z)
            return false;
        if (x == z || y == z || x + y == z || (z % gcd(x, y)) == 0)
            return true;
        else
            return false;
    }
};
// @lc code=end

