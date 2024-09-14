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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int l=0;
        while(q.size()) {
            ans.push_back({});
            int s=q.size();
            while(s--) {
                auto f = q.front();
                q.pop();
                ans[l].push_back(f->val);
                if(f->left) {
                    q.push(f->left);
                }
                if(f->right) {
                    q.push(f->right);
                }
            }
            l++;
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