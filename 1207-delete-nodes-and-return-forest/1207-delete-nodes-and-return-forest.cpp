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
    TreeNode* solve(TreeNode* root, vector<int>& del, vector<TreeNode*>& ans) {
        if(!root) 
            return nullptr;

        root->right = solve(root->right, del, ans);
        root->left = solve(root->left, del, ans);

        if(binary_search(del.begin(), del.end(), root->val)) {
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            return nullptr;
        }
        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) {
        vector<TreeNode*> ans;
        sort(del.begin(), del.end());
        root = solve(root, del, ans);
        if(root) ans.push_back(root);
        return ans;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();