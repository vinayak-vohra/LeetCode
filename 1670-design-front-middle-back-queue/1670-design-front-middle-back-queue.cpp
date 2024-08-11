class FrontMiddleBackQueue {
    deque<int> a, b;
    void shiftToB() {
        if (a.size() > b.size()) {
            b.push_front(a.back());
            a.pop_back();
        }
    }
    void shiftToA() {
        if (a.size() < b.size()) {
            a.push_back(b.front());
            b.pop_front();
        }
    }

public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) {
        shiftToB();
        a.push_front(val);
    }

    void pushMiddle(int val) {
        shiftToB();
        a.push_back(val);
    }

    void pushBack(int val) {
        b.push_back(val);
        shiftToA();
    }

    int popFront() {
        if (!a.size())
            return -1;

        int p = a.front();
        a.pop_front();
        shiftToA();
        return p;
    }

    int popMiddle() {
        if (!a.size())
            return -1;
        int p = a.back();
        a.pop_back();
        shiftToA();
        return p;
    }

    int popBack() {
        shiftToB();
        if (!b.size())
            return -1;

        int p = b.back();
        b.pop_back();
        return p;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();