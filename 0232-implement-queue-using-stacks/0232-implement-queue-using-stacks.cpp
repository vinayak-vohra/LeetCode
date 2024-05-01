class MyQueue {
    vector<int8_t> stk1, stk2;
    int8_t front;

public:
    MyQueue() {
        front = 0;
        stk1.reserve(100);
        stk2.reserve(100);
    }
    
    void push(int x) {
        if(stk1.empty()) 
            front = x;
        stk1.push_back(x);
    }
    
    int pop() {
        if(stk2.empty()){
            while(!stk1.empty()){
                auto x = *(stk1.end() - 1);
                stk1.pop_back();
                stk2.push_back(x);
            }
        }
        auto x = *(stk2.end() - 1);
        stk2.pop_back();
        return x;
    }
    
    int peek() {
        return stk2.empty() ? front : *(stk2.end() - 1);
    }
    
    bool empty() {
        return stk1.empty() && stk2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */