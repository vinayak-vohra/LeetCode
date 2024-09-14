class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, INT_MAX);
        dp.back() = 0;
        for (int i = n - 2; i >= 0; i--) {
            int mini = *min_element(dp.begin() + i,
                                    dp.begin() + min(i + nums[i] + 1, n));
            if (mini != INT_MAX)
                dp[i] = mini + 1;
        }
        return dp[0];
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();