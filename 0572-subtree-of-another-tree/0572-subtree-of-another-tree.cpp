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
bool ans=false;
class Solution {
    bool isSameTree(TreeNode* p, TreeNode* q, bool result = true) {
        if (!q &&!p) return true;
            

        if (((bool)p ^ (bool)q) || (p->val != q->val))
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        ans = isSameTree(root, subRoot);
        if(!ans && root->left) ans = isSubtree(root->left, subRoot);
        if(!ans && root->right) ans = isSubtree(root->right, subRoot);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();