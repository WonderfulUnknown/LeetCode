/*
 * @lc app=leetcode.cn id=902 lang=cpp
 *
 * [902] 最大为 N 的数字组合
 */

// @lc code=start
class Solution {
public:
    vector<int> digits(int n) {
        vector<int> res;
        while (n > 0) 
        {
            res.push_back(n % 10);
            n /= 10;
        }
        return res;
    }
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        vector<int> smaller(11,0);
        for (auto& x : D) 
            smaller[x[0] - '0' + 1]++;//i比i+1小 
        for (int i = 1; i <= 10; i++)
            smaller[i] += smaller[i - 1];
        vector<int> num = digits(N);
        int len = num.size();
        vector<int> temp(len,1);
        int res = 0;
        //位数少于N
        for (int i = 1; i < len; i++)
        {
            temp[i] = temp[i - 1] * D.size();
            res += temp[i];
        }
        //位数等于N
        bool if_equal = true;
        for (int i = len - 1; i >= 0; i--)
        {
            res += temp[i] * smaller[num[i]];
            if (smaller[num[i]] == smaller[num[i] + 1])
            {
                if_equal = false;
                break;
            }
        }
        res += if_equal;
        return res;
    }
};

// @lc code=end

