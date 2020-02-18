/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    int countSquareNum(int n ){
        int result = 0, temp;
        while(n > 0)
        {
            temp = n % 10;
            n = n / 10;
            result += temp * temp; 
        }
        return result;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = countSquareNum(slow);
            fast = countSquareNum(fast);
            fast = countSquareNum(fast);
        }while(slow != fast);

        return slow == 1;
    }
};
// @lc code=end

