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
    ListNode* deleter(ListNode* head, int n, int &count) {
        if(!head)
            return nullptr;
        
        head->next = deleter(head->next, n, count);
        count++;

        if(count==n)
            return head->next;
        return head;

    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        return deleter(head, n, count);
    }
};
