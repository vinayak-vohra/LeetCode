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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxSum = INT_MIN;
        int ans = 0;
        int l = 1;
        while (q.size()) {
            int s = q.size();
            int thisLevel = 0;

            while (s--) {
                auto node = q.front();
                q.pop();
                thisLevel += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            if (thisLevel > maxSum) {
                maxSum = thisLevel;
                ans = l;
            }
            ++l;
        }
        return ans;
    }
};