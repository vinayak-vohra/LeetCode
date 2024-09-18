class MyCircularQueue {
    int *arr, front, rear, size;

public:
    MyCircularQueue(int k) {
        size = k;
        arr = new int[k];
        front = rear = -1;
    }

    bool enQueue(int value) {
        int r = (rear + 1) % size;
        if (r == front)
            return false;

        arr[r] = value;
        rear = r;
        if (front < 0)
            front = 0;
        return true;
    }

    bool deQueue() {
        if (front < 0)
            return false;

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
        return true;
    }

    int Front() {
        if (front < 0)
            return -1;
        return arr[front];
    }

    int Rear() {
        if (rear < 0)
            return -1;
        return arr[rear];
    }

    bool isEmpty() { return front < 0; }

    bool isFull() { return (rear + 1) % size == front; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */