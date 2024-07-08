class Node {
public:
    int val;
    Node* next;
    Node() : val(0), next(nullptr) {}
    Node(int v) : val(v), next(nullptr) {}
    Node(int v, Node* n) : val(v), next(n) {}
};

class Solution {

public:
    int findTheWinner(int n, int k) {
        Node *head, *tail;
        head = tail = nullptr;

        // convert to circular linked list
        for (int i = 1; i <= n; ++i) {
            Node* node = new Node(i, head);
            if (!head) {
                head = tail = node;
                node->next = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }

        // simulate
        while (head->next != head) {
            int x = k;
            while (--x) {
                tail = head;
                head = head->next;
            }
            tail->next = head->next;
            head = head->next;
        }
        return head->val;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();