/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.empty())
			return intervals;
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> res;
		int i = 0, j = 1;
		while (j < intervals.size())
		{
			if (intervals[i][1] >= intervals[j][0])
			{
				if (intervals[i][1] <= intervals[j][1])
					intervals[i][1] = intervals[j][1];
				j++;
			}
			//如果和相邻的区间都不会合并，和后面的区间更不可能
			else
			{
				res.emplace_back(intervals[i]);
				i = j;
				j++;
			}
		}
		res.emplace_back(intervals[i]);
		return res;
	}
};
// @lc code=end

