class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        long long ans = 0;
        for (int i = 0; i < n - 1; i++) {
            ans +=
                upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) -
                lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
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

// -7 -7 -5 -5 -5