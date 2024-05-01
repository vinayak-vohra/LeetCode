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
  bool isEvenOddTree(TreeNode *root) {
    queue<TreeNode *> q;

    q.push(root);
    bool level = 0;

    while (q.size()) {
      int count = q.size();
      int prev = level ? 1e6+1 : 0;
      while (count--) {
        auto node = q.front();
        q.pop();

        // odd level:
        // - even values
        // - val < prev

        // even level:
        // - odd values
        // - val > prev
        if (level && ((node->val & 1) || node->val >= prev) ||
            !level && (!(node->val & 1) || node->val <= prev))
          return false;

        if(node->left)
            q.push(node->left);

        if(node->right)
            q.push(node->right);
          
        prev = node->val;
      }
      level = !level;
    }
    return true;
  }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();