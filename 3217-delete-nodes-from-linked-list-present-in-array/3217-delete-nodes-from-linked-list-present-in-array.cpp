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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> rem(nums.begin(), nums.end());
        ListNode* temp = head;
        ListNode* newHead = head;
        ListNode* prev = nullptr;
        while (temp) {
            if (rem.count(temp->val)) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    newHead = temp->next;
                }
            } else {
                prev = temp;
            }
            temp = temp->next;
        }
        return newHead;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();