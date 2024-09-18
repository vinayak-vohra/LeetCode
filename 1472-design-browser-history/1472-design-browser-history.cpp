class BrowserHistory {
    vector<string> history;
    int cur, last;

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        cur = last = 0;
    }

    void visit(string url) {
        if (cur == history.size() - 1) {
            history.push_back(url);
            ++cur;
        } else {
            history[++cur] = url;
        }
        last = cur;
    }

    string back(int steps) {
        cur = max(0, cur - steps);
        return history[cur];
    }

    string forward(int steps) {
        cur = min(cur + steps, last);
        return history[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

// e kt cr iy