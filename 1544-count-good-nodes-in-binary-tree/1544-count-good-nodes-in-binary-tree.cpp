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
    void solve(TreeNode* root, int mx, int& ans) {
        if (!root)
            return;
        if (root->val >= mx)
            ++ans;
        mx = std::max(root->val, mx);
        solve(root->left, mx, ans);
        solve(root->right, mx, ans);
    }

public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        solve(root, root->val, ans);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();