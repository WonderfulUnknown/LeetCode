/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		if (nums.size() == 1)
			return 0;
		int left, right, mid;
		left = 0;
		right = nums.size() - 1;
		while (left < right)
		{
			mid = (left + right) / 2;
			if (nums[mid] <= nums[mid + 1])
				left = mid + 1;
			else
				right = mid;
		}
		return left;
	}
};
// @lc code=end

