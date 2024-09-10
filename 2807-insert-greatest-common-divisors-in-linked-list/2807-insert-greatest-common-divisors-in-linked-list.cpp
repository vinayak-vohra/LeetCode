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
// int gcd(int a, int b) {
//     if (!b)
//         return a;
//     return gcd(b, a % b);
// }
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head) {
            ListNode *prev = head, *cur = head->next;
            while (cur) {
                prev->next = new ListNode(__gcd(prev->val, cur->val), cur);
                prev = cur;
                cur = cur->next;
            }
        }

        return head;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();