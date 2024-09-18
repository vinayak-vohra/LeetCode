class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        unordered_map<size_t, int> mp;
        int ans = 1;
        for (int i = n - 1; i >= 0; i--) {
            mp[nums[i]] = (mp[(size_t)nums[i] * (size_t)nums[i]] + 1);
            ans = max(ans, mp[nums[i]]);
        }
        return ans == 1 ? -1 : ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();