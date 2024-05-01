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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        stack<ListNode*> s;
        auto *slow = head, *fast = head;

        while (fast && fast->next) {
            s.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast)
            slow = slow->next;

        while (slow) {
            if (s.empty() || s.top()->val != slow->val)
                return false;

            s.pop();
            slow = slow->next;
        }
        return true;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();