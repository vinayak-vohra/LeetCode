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
    void solve(TreeNode* root, vector<int>& cur, vector<vector<int>>& ans,
               int ts) {
        if (!root)
            return;

        ts -= root->val;

        // if (ts < 0)
        //     return;

        cur.push_back(root->val);
        if (!root->left && !root->right) {
            if (!ts)
                ans.push_back(cur);
        } else {
            solve(root->left, cur, ans, ts);
            solve(root->right, cur, ans, ts);
        }
        cur.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> cur;
        vector<vector<int>> ans;
        solve(root, cur, ans, targetSum);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();