class MyCircularDeque {
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int d = 0, Node* n = nullptr, Node* p = nullptr)
            : data(d), next(n), prev(p) {}
    };
    Node *head, *tail;
    int size, capacity;

    bool insert(int value, bool isHead = 0) {
        if (size == capacity)
            return false;

        Node* node = new Node(value, head, tail);
        if (!head) {
            head = tail = node;
        }
        head->prev = node;
        tail->next = node;

        if (isHead)
            head = head->prev;
        else
            tail = tail->next;
        size++;
        return true;
    }

    bool erase(bool isHead = 0) {
        if (size == 0)
            return false;
        Node* del = isHead ? head : tail;

        if (head == tail) {
            head = tail = nullptr;
        } else {
            if (isHead)
                head = head->next;
            else
                tail = tail->prev;
            head->prev = tail;
            tail->next = head;
        }
        size--;
        delete del;
        return true;
    }

public:
    MyCircularDeque(int k) {
        head = tail = nullptr;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value) { return insert(value, 1); }

    bool insertLast(int value) { return insert(value); }

    bool deleteFront() { return erase(1); }

    bool deleteLast() { return erase(); }

    int getFront() {
        if (size == 0)
            return -1;
        return head->data;
    }

    int getRear() {
        if (size == 0)
            return -1;
        return tail->data;
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

 auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

// 9 7 0