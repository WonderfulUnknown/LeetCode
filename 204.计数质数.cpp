/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        int *isPrime;
        isPrime = new int [n];
        for (int i = 0; i < n; i++)
            isPrime[i] = 1;
        for (int i = 2; i * i < n; i++)
        {
            if (isPrime[i])
            {
                int temp = 2;
                while (temp * i < n)
                {
                    isPrime[temp * i] = 0;
                    temp++;
                }
            }
        }
        int res = 0;
        for (int i = 2; i < n; i++)
            res += isPrime[i];
        return res;
    }
};
// @lc code=end

