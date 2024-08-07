class RecentCounter {
    vector<int> q;
    int i;

public:
    RecentCounter() { i = 0; }

    int ping(int t) {
        int r = t - 3000;
        while (i < q.size() && q[i] < r)
            ++i;
        q.push_back(t);
        return q.size() - i;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();