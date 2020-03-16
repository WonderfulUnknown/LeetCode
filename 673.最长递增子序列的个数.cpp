/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		int n = nums.size();
		//dp[i]表示以nums[i]结尾的递增子序列的最大长度
		vector<int> dp(n, 1);
		//count[i]表示以nums[i]结尾的最长递增子序列的路径数
		vector<int> count(n, 1);
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (nums[i] > nums[j])
				{
					if (dp[j] + 1 > dp[i])
					{
						dp[i] = dp[j] + 1;
						count[i] = count[j];
					}
					else if (dp[j] + 1 == dp[i])
						count[i] += count[j];
				}
			}
		}
		int res = 0, max = -1;
		for (int i = 0; i < n; i++)
		{
			if (dp[i] > max)
			{
				max = dp[i];
				res = count[i];
			}
			else if (dp[i] == max)
				res += count[i];
		}
		return res;
	}
};
// @lc code=end

