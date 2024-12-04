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

public:
    bool flipEquiv(TreeNode* a, TreeNode* b) {
        if (!a && !b)
            return true;
        if (a && b) {
            if (a->val != b->val)
                return false;
            bool left = flipEquiv(a->left, b->left);
            bool right = flipEquiv(a->right, b->right);

            if (left && right)
                return true;

            if (!left && !right)
                return flipEquiv(a->left, b->right) && flipEquiv(a->right, b->left);

            return false;
        }
        return false;
    }
};