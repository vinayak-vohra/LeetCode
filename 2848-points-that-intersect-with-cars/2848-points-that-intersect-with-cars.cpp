class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> prev = nums[0];
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i][0] <= prev[1])
                prev[1] = max(nums[i][1], prev[1]);
            else {
                ans += (prev[1] - prev[0] + 1);
                prev = nums[i];
            }
        }
        return ans + (prev[1] - prev[0] + 1);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
