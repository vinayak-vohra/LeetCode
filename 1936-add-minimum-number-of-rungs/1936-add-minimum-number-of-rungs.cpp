class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int ans = 0, prev = 0;
        for (int x : rungs) {
            int diff = x - prev;
            if (diff > dist) {
                ans += ceil((double)diff / dist) - 1;
            }
            prev = x;
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