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
const pair<int, int> base = {INT_MIN, INT_MAX};
class Solution {
    pair<int, int> solve(TreeNode* root, int& ans) {
        if (!root)
            return base;

        if (!root->left && !root->right)
            return {root->val, root->val};

        int maxi, mini;
        maxi = mini = root->val;
        if (root->left) {
            auto lt = solve(root->left, ans);
            ans = min(ans, root->val - lt.first);
            mini = lt.second;
        }
        if (root->right) {
            auto rt = solve(root->right, ans);
            ans = min(ans, rt.second - root->val);
            maxi = rt.first;
        }
        return {maxi, mini};
    }

public:
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
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