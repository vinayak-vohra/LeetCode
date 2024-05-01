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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1)
            return new TreeNode(val, root, nullptr);

        int level = 1;
        queue<TreeNode*> q;
        q.push(root);
        bool done = 0;

        while (!done) {
            int x = q.size();
            while (x--) {
                auto n = q.front();
                q.pop();

                if (level == depth - 1) {
                    done = 1;
                    n->left = new TreeNode(val, n->left, nullptr);
                    n->right = new TreeNode(val, nullptr, n->right);
                } else {
                    if (n->left)
                        q.push(n->left);
                    if (n->right)
                        q.push(n->right);
                }
            }
            level++;
        }
        return root;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();