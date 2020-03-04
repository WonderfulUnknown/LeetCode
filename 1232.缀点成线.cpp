/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
 */

// @lc code=start
class Solution {
public:
	bool checkStraightLine(vector<vector<int>>& coordinates) {
		for (int i = 2; i < coordinates.size(); i++)
		{
			if ((coordinates[i][1] - coordinates[0][1]) * (coordinates[1][0] - coordinates[0][0]) !=
				(coordinates[1][1] - coordinates[0][1]) * (coordinates[i][0] - coordinates[0][0]))
				return false;
		}
		return true;
	}
};
// @lc code=end

