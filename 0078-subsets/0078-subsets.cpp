class Solution {
    void solve(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans,
               int idx = 0) {
        if (idx == nums.size()) {
            ans.push_back(temp);
            return;
        }

        solve(nums, temp, ans, idx + 1);

        temp.push_back(nums[idx]);
        solve(nums, temp, ans, idx + 1);
        temp.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums, temp, ans);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();