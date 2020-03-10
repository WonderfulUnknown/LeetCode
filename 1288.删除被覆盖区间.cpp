/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 *
 * [1288] 删除被覆盖区间
 */

// @lc code=start
class Solution {
public:
	int removeCoveredIntervals(vector<vector<int>>& intervals) {
		sort(intervals.begin(),intervals.end());
		for (int i = 0; i < intervals.size(); i++)
		{
			for (int j = i + 1; j < intervals.size(); j++)
			{
				if (intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1])
				{
					intervals.erase(intervals.begin() + j);
					j--;
				}
			}
		}
		return intervals.size();
	}
};
// @lc code=end

