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
    bool isSameTree(TreeNode* p, TreeNode* q, bool result = true) {
        if(!p && !q)
            return true;

        if(((bool)p ^ (bool)q) || (p->val != q->val))
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    // if (bool(p) != bool(q) || (bool(p) && bool(q) && p->val != q->val))
    //     return false;

    // result = isSameTree(p->left, q->left, result);
    // result = isSameTree(p->right, q->right, result);

    // return result;
    }  
};
