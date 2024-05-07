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
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head || !head->next)
            return head;

        ListNode *kFromBeg, *kFromEnd;
        kFromBeg = kFromEnd = head;
        while (--k)
            kFromBeg = kFromBeg->next;

        auto temp = kFromBeg;

        while (kFromBeg->next) {
            kFromEnd = kFromEnd->next;
            kFromBeg = kFromBeg->next;
        }
        int tval = temp->val;
        temp->val = kFromEnd->val;
        kFromEnd->val = tval;
        // std::swap(temp->val, kFromEnd->val);
        return head;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();