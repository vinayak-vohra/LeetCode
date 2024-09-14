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
    TreeNode* builder(vector<int>& postorder, vector<int>& inorder, int l,
                      int r, int& i) {
        if (i < 0 || l >= r)
            return nullptr;

        int idx = find(inorder.begin() + l, inorder.begin() + r, postorder[i]) -
                  inorder.begin();

        TreeNode* node = new TreeNode(postorder[i]);
        --i;
        node->right = builder(postorder, inorder, idx + 1, r, i);
        node->left = builder(postorder, inorder, l, idx, i);
        return node;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = inorder.size() - 1;
        return builder(postorder, inorder, 0, i + 1, i);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();