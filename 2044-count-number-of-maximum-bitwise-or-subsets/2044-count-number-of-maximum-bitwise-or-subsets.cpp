class Solution {
    void solve(vector<int>& arr, int idx, int cur, int tar, int& ans) {
        if (idx < 0)
            return;

        // skip
        solve(arr, idx - 1, cur, tar, ans);

        cur |= arr[idx];

        // pick
        solve(arr, idx - 1, cur, tar, ans);

        if (cur == tar)
            ans++;
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        int tar = accumulate(begin(nums), end(nums), 0, std::bit_or<int>());
        int ans = 0;
        solve(nums, nums.size() - 1, 0, tar, ans);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();