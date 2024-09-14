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
pair<int, int> base = {INT_MIN, INT_MAX};
class Solution {
    pair<int, int> solve(TreeNode* root, bool& ans) {
        if (!root)
            return base;

        auto lt = solve(root->left, ans);
        if (lt != base && lt.first >= root->val) {
            ans = false;
            return base;
        }

        auto rt = solve(root->right, ans);
        if (rt != base && rt.second <= root->val) {
            ans = false;
            return base;
        }

        return {max(root->val, rt.first), min(root->val, lt.second)};
    }

public:
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        solve(root, ans);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();