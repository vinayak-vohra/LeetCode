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
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};

        stack<TreeNode *> stk;
        stk.push(nullptr);
        vector<int> resultSet;
        TreeNode *ptr = root;

        while (ptr)
        {
            while (ptr)
            {
                stk.push(ptr);
                ptr = ptr->left;
            }

            while (!stk.empty())
            {
                ptr = stk.top(), stk.pop();

                if (!ptr)
                    break;

                resultSet.push_back(ptr->val);
                if (ptr->right)
                {
                    ptr = ptr->right;
                    break;
                }
            }
        }
        return resultSet;
    }
};