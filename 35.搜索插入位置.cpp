/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 暴力查找
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] > target || nums[i] == target)
        //         return i;
        // }
        // return nums.size();

        // 二分查找
        int left, right, mid;
        left = 0;
        right = nums.size() - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};
// @lc code=end

