constexpr int MOD = 1e9 + 7;
constexpr int modAdd(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ps(n + 1, 0);
        vector<int> sums;

        for (int i = 0; i < n; ++i)
            ps[i + 1] = modAdd(ps[i], nums[i]);

        ps.push_back(0);

        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j)
                sums.push_back(ps[j] - ps[j - i]);
        }

        sort(sums.begin(), sums.end());

        return std::accumulate(sums.begin() + left - 1, sums.begin() + right, 0,
                               modAdd);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();