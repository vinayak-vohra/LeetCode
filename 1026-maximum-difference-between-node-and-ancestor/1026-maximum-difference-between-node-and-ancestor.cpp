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
#define minMax pair<int, int>
#define base minMax(INT_MAX, INT_MIN)

class Solution {
public:
    int maxDiff = INT_MIN;

    minMax compare(minMax a, minMax b)
    {
        return {min(a.first, b.first), max(a.second, b.second)};
    }

    minMax solve(TreeNode* root)
    {
        if(!root)
            return base;
        
        if(!root->left && !root->right)
            return {root->val, root->val};

        auto mm = compare(solve(root->left), solve(root->right));
        maxDiff = max(maxDiff, max(abs(mm.first - root->val), abs(mm.second - root->val)));
        return compare(mm, {root->val, root->val});
    }

    int maxAncestorDiff(TreeNode* root) {
        solve(root);
        return maxDiff;
    }
};