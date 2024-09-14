/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()) {
            int s=q.size();
            int maxi = INT_MIN;
            while(s--) {
                auto f = q.front();
                q.pop();
                maxi = max(maxi, f->val);
                if(f->left) q.push(f->left);                
                if(f->right) q.push(f->right);
            }
            ans.push_back(maxi);
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