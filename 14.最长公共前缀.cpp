/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty())
			return {};
		int min_len = INT_MAX;
		for (int i = 0; i < strs.size(); i++)
		{
			if (min_len > strs[i].size())
				min_len = strs[i].size();
		}
		int min = INT_MAX;
		for (int i = 1; i < strs.size(); i++)
		{
			int temp = INT_MAX;
			for (int j = 0; j < min_len; j++)
			{
				if (strs[0][j] != strs[i][j])
				{
					temp = j;
					break;
				}
			}
			if (min > temp && temp >= 0)
				min = temp;
		}
		string res;
		for (int i = 0; i < min && i < min_len; i++)
			res = res + strs[0][i];
		return res;
	}
};
// @lc code=end

