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
    void solve(TreeNode* root, long& min1, long& min2) {
        if (!root)
            return;
        solve(root->left, min1, min2);
        solve(root->right, min1, min2);
        if (root->val < min1) {
            min2 = min1;
            min1 = root->val;
        } else if (root->val < min2 && root->val != min1)
            min2 = root->val;
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        long m1 = LONG_MAX, m2 = LONG_MAX;
        solve(root, m1, m2);
        return m2 == LONG_MAX ? -1 : m2;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();