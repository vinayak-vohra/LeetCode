#pragma GCC optimize("03", "unroll-loops")
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i < n + 1; ++i)
            prefix[i] = prefix[i - 1] + nums[i - 1];

        double ans = LONG_LONG_MIN;
        for (int i = k; i < n + 1; ++i) {
            ans = std::max(ans, ((prefix[i] - prefix[i - k]) / (double)k));
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