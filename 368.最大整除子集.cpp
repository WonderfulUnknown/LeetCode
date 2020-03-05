/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */

// @lc code=start
class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int n = nums.size();
        if (n <= 1)
            return nums;

		vector<int> dp(n, 1);	//dp[i]表示包含i,有几个数符合条件
		vector<int> path(n, -1);//path[i]表示在dp[i]加入的最大数的下标

		sort(nums.begin(), nums.end());
		
		int index;
		int max = INT_MIN;
		//判断num[i]能被哪些数整除
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				//num[i]能被num[j]整除，且j要是最接近i的
				if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
				{
					dp[i] = dp[j] + 1;
					path[i] = j;
				}
				if (max < dp[i])
				{
					max = dp[i];
					index = i;
				}
			}
		}
		vector<int> res;
		for (int i = 0; i < max; i++)
		{
			res.push_back(nums[index]);
			index = path[index];
		}
		return res;
	}
};
// @lc code=end

