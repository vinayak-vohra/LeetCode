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
    void solve(TreeNode* root, unsigned int& sum, unsigned int& num) {
        if (!root)
            return;

        num <<= 1;
        num |= root->val;

        if (!root->left && !root->right) {
            sum += num;
            num >>= 1;
            return;
        }
        solve(root->left, sum, num);
        solve(root->right, sum, num);
        num >>= 1;
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        unsigned int sum = 0, num = 0;
        solve(root, sum, num);
        return sum;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();