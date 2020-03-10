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
		int len = intervals.size();
		vector<int> begin;
		vector<int> end;
		for (int i = 0; i < len; i++)
		{
			begin.push_back(intervals[i][0]);
			end.push_back(intervals[i][1]);
		}
		for (int i = 0; i < begin.size(); i++)
		{
			for (int j = i + 1; j < begin.size(); j++)
			{
				if (begin[i] <= begin[j] && end[i] >= end[j])
				{
					begin.erase(begin.begin() + j);
					end.erase(end.begin() + j);
					j--;
				}
			}
		}
		return begin.size();
	}
};
// @lc code=end

