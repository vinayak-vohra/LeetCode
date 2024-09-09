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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        auto temp = head;
        int c = 0;
        while (temp && temp->next) {
            c++;
            temp = temp->next->next;
        }
        c *= 2;
        c += ((bool)temp);
        vector<ListNode*> ans(k);

        int i = 0;
        while (head && i < k) {
            ans[i++] = (head);
            for (int j = 1; j < (c / k + (i <= c % k)); j++)
                head = head->next;

            if (head) {
                temp = head;
                head = head->next;
                temp->next = nullptr;
            }
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();