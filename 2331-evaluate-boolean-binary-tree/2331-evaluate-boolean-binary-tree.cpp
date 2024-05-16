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
    bool evaluateTree(TreeNode* root) {
        if (!root->left && !root->right)
            return root->val;

        if (root->val == 2) { // or
            if (root->left->val == 1 || root->right->val == 1)
                return 1;
            return evaluateTree(root->left) || evaluateTree(root->right);
        }

        if (root->val == 3) { // and
            if (root->left->val == 0 || root->right->val == 0)
                return 0;
            return evaluateTree(root->left) && evaluateTree(root->right);
        }

        // shouldn't reach here
        return 1;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();