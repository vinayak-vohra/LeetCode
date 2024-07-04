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
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *x, *y, *head1;
        x = head1 = head;
        y = x->next;

        while (x) {
            while (y && y->val) {
                x->val += y->val;
                y = y->next;
            }
            if (!y->next)
                break;

            x->next = y;
            x = y;
            y = y->next;
        }
        x->next = nullptr;
        return head1;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();