/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next)
            return false;

        ListNode *slow, *fast;
        slow = fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // if (!fast || !fast->next)
            //     return false;
            if (fast == slow)
                return true;
        }
        return false;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();