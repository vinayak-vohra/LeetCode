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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root); 

        while(q.size()) {
            int s = q.size();
            ans.push_back(q.front()->val);

            while(s--) {
                auto f = q.front();
                q.pop();
                if(f->right) q.push(f->right);
                if(f->left) q.push(f->left);
            }
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