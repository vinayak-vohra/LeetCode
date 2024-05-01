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
    void saveLeaves(TreeNode* root, vector<int> &vect)
    {
        if(!(root->left||root->right))
        {
            vect.push_back(root->val);
            return;
        }

        if(root->left)
            saveLeaves(root->left, vect);

        if(root->right)
            saveLeaves(root->right, vect);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1, t2;
        saveLeaves(root1, t1);
        saveLeaves(root2, t2);
        return t1==t2;
    }
};