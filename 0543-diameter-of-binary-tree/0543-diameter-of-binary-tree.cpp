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
    int diameter(TreeNode* root, int &dia) {
        if (!root)
            return 0;

        int lt = diameter(root->left, dia);
        int rt = diameter(root->right, dia);

        dia = max(dia, lt + rt);
        return 1 + max(lt, rt);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        diameter(root, dia);
        return dia;
    }
};
// auto init = [](){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     return 'c';
// }();