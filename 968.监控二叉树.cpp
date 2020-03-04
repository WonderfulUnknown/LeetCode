/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int num = 0;
	//0:初始 1:安装摄像头 2:被监视 3:未被监视
	int dfs(TreeNode* root) {
		if (!root)
			return 2;
		int left, right;
		left = dfs(root->left);
		right = dfs(root->right);
		//先顾及孩子是否未被监视
        if (left == 3 || right == 3)
		{
			num++;
			return 1;
		}
		else if (left == 1 || right == 1)
			return 2;
		else
			return 3;
	}

	int minCameraCover(TreeNode* root) {
		if (dfs(root) == 3)
			num++;
		return num;
	}
};
// @lc code=end

