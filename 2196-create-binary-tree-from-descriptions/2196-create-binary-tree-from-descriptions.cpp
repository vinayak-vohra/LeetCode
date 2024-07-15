#pragma GCC optimize("03", "unroll-loops")
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<TreeNode*, bool> isChildNode;

        for (auto& desc : descriptions) {
            int p = desc[0], c = desc[1], l = desc[2];

            if (!mp[p]) {
                mp[p] = new TreeNode(p);
            }

            if (!mp[c]) {
                mp[c] = new TreeNode(c);
            }

            if (l)
                mp[p]->left = mp[c];
            else
                mp[p]->right = mp[c];

            isChildNode[mp[p]] |= 0;
            isChildNode[mp[c]] |= 1;
        }

        for (auto& pr : isChildNode)
            if (!pr.second)
                return pr.first;

        return nullptr;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();