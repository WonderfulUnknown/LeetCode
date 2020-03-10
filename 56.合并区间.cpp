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
        sort(intervals.begin(),intervals.end());
        for (int i = 0; i < intervals.size(); i++)
		{
			for (int j = i + 1; j < intervals.size(); j++)
			{
                if (intervals[i][1] >= intervals[j][0])
                {
                    if (intervals[i][1] < intervals[j][1])
						intervals[i][1] = intervals[j][1];
					intervals.erase(intervals.begin() + j);
					j--;
                }
			}
		}
		return intervals;
    }
};
// @lc code=end

