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
    TreeNode* builder(vector<int>& preorder, vector<int>& inorder, int l, int r,
                      int& i) {
        if (i == preorder.size() || l >= r)
            return nullptr;

        int idx = find(inorder.begin() + l, inorder.begin() + r, preorder[i]) -
                  inorder.begin();

        TreeNode* node = new TreeNode(preorder[i]);
        ++i;
        node->left = builder(preorder, inorder, l, idx, i);
        node->right = builder(preorder, inorder, idx + 1, r, i);
        return node;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0;
        return builder(preorder, inorder, 0, preorder.size(), i);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();