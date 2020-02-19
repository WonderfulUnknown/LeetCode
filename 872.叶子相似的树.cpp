/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] 叶子相似的树
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
    //传递vector可能会堆栈爆炸，考虑使用迭代器
    void leafSearch(TreeNode* root, vector<int>& leaves)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
            leaves.push_back(root->val);
        leafSearch(root->left, leaves);
        leafSearch(root->right, leaves);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> lea1, lea2;
        leafSearch(root1, lea1);
        leafSearch(root2, lea2);
        if(lea1 == lea2)
            return true;
        else 
            return false;
    }
};
// @lc code=end

