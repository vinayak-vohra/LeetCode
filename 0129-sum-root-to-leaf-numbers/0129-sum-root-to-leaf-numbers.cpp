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
    void solve(TreeNode* root, size_t& sum, size_t curSum = 0) {
        if (!root)
            return;

        curSum = curSum * 10 + root->val;
        if (root->left)
            solve(root->left, sum, curSum);

        if (root->right)
            solve(root->right, sum, curSum);

        if (!root->left && !root->right)
            sum += curSum;
    }

public:
    int sumNumbers(TreeNode* root) {
        size_t sum = 0;
        solve(root, sum);
        return sum;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();