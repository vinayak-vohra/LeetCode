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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return {-1, -1};
        int i = 2, first = -1, last = -1, min = INT_MAX;
        ListNode *prev = head, *curr = head->next;

        while (curr->next) {
            if ((prev->val < curr->val && curr->next->val < curr->val) ||
                (prev->val > curr->val && curr->next->val > curr->val)) {
                if (first < 0)
                    first = i;
                if (last > 0)
                    min = std::min(min, i - last);
                last = i;
            }
            i++;
            prev = curr;
            curr = curr->next;
        }
        if (first == last)
            return {-1, -1};
        return {min, last - first};
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
