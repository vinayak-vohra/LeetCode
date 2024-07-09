class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double wt = customers[0][1];
        int prev = customers[0][0] + customers[0][1];

        for (int ci = 1; ci < n; ++ci) {
            auto& tt = customers[ci];
            int at = tt[0];

            int st = max(at, prev);
            int et = st + tt[1];
            prev = et;
            wt += et - at;
        }

        return wt / n;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();