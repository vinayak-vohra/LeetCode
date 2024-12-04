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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<size_t, vector<size_t>, greater<size_t>> pq;
        queue<TreeNode*> q;
        q.push(root);

        while (q.size()) {
            int s = q.size();
            size_t ls = 0;

            while (s--) {
                auto front = q.front();
                q.pop();
                ls += front->val;

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }

            pq.push(ls);
            if (pq.size() > k)
                pq.pop();
        }

        if (pq.size() < k)
            return -1;
        return static_cast<long long>(pq.top());
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();