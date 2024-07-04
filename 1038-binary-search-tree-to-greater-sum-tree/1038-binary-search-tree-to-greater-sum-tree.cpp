/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int curMax;

public:
    Solution() { curMax = 0; }
    TreeNode* bstToGst(TreeNode* root) {
        if (!root)
            return nullptr;

        if (root->right) {
            root->right = bstToGst(root->right);
        }
        curMax += root->val;
        root->val = curMax;
        if (root->left) {
            root->left = bstToGst(root->left);
        }
        return root;
    }
};