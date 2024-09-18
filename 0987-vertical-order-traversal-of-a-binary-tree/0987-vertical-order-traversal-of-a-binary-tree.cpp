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
    void solve(TreeNode* root, unordered_map<int, vector<pair<int, int>>>& mp,
               int& mini, int& maxi, int row = 0, int col = 0) {
        if (!root)
            return;
        mini = min(mini, col);
        maxi = max(maxi, col);

        mp[col].push_back({row, root->val});
        solve(root->left, mp, mini, maxi, row + 1, col - 1);
        solve(root->right, mp, mini, maxi, row + 1, col + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int mini = 0, maxi = 0;
        unordered_map<int, vector<pair<int, int>>> mp;
        solve(root, mp, mini, maxi);

        vector<vector<int>> ans(maxi - mini + 1);

        for (auto& v : ans) {
            sort(mp[mini].begin(), mp[mini].end());
            v = vector<int>(mp[mini].size());
            transform(mp[mini].begin(), mp[mini].end(), v.begin(),
                      [](const pair<int, int> p) { return p.second; });

            mini++;
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
