/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* findMid(ListNode* low, ListNode* high) {
        if (!low || low->next == high)
            return low;
        ListNode *slow = low, *fast = low->next;

        while (fast != high && fast->next != high) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    TreeNode* sortedListToBST(ListNode* low, ListNode* high = nullptr) {
        if (low == high)
            return nullptr;

        ListNode* mid = findMid(low, high);
        TreeNode* node = new TreeNode(mid->val);
        node->left = sortedListToBST(low, mid);
        node->right = sortedListToBST(mid->next, high);
        return node;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();