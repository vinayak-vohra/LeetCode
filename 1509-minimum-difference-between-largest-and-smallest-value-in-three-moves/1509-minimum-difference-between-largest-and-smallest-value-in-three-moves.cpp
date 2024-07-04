class Solution {
public:
    int minDifference(vector<int>& nums) {
        int s = nums.size();
        if (s <= 4)
            return 0;

        sort(nums.begin(), nums.end());

        int ans = nums[s - 1] - nums[0];
        for (int i = 0; i < 4; i++) {
            ans = min(ans, nums[s - (3 - i) - 1] - nums[i]);
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