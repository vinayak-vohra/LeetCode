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
class Solution {
    ListNode* solve(ListNode* node) {
        if (!node->next)
            return node;

        ListNode* prev = solve(node->next);
        if (node->val < prev->val) {
            // delete node;
            return prev;
        }
        node->next = prev;
        return node;
    }

public:
    ListNode* removeNodes(ListNode* head) {
        if (!head || !head->next)
            return head;
        return solve(head);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();