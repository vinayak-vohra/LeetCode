class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        auto it = nums.begin();
        while (it != nums.end()) {
            auto lb = lower_bound(it, nums.end(), *it + 1);
            if (lb != nums.end() && *lb == *it + 1) {
                ans = max(ans, static_cast<int>(
                                   upper_bound(lb, nums.end(), *it + 1) - it));
            }
            it = lb;
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