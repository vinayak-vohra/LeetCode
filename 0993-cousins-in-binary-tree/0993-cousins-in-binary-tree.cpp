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

    void solve(TreeNode* root, int x, int y, pair<int, int>& dx, pair<int, int>& dy, int& parent,
               int d = 1) {
        if (!root || (dx.first && dy.first))
            return;

        if (root->val == x) {
            dx.first = d;
            dx.second = parent;
        }
        if (root->val == y) {
            dy.first = d;
            dy.second = parent;
        }

        solve(root->left, x, y, dx, dy, root->val, d + 1);
        solve(root->right, x, y, dx, dy, root->val, d + 1);
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int, int> dx, dy;
        int parent = -1;
        solve(root, x, y, dx, dy, parent);
        // cout << dx << ' ' << dy;
        return (dx.first == dy.first && dx.second != dy.second);
    }
};