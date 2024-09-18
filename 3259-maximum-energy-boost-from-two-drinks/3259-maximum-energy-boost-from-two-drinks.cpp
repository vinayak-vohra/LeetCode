class Solution {
public:
    long long maxEnergyBoost(vector<int>& edA, vector<int>& edB) {
        int n = edA.size();
        vector<long long> dpA(n + 1, 0), dpB(n + 1, 0);
        dpA[1] = edA[0];
        dpB[1] = edB[0];

        for (int i = 2; i <= n; i++) {
            dpA[i] = max(dpA[i - 1], dpB[i - 2]) + edA[i - 1];
            dpB[i] = max(dpB[i - 1], dpA[i - 2]) + edB[i - 1];
        }
        return max(dpA[n], dpB[n]);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();