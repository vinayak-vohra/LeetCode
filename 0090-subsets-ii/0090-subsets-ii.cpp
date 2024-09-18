class Solution {
    void solve(vector<vector<int>>& ans, vector<int>& save, vector<int>& nums,
               vector<int>::iterator it) {
        if (it == nums.end()) {
            ans.push_back(save);
            return;
        }

        // pick
        save.push_back(*it);
        solve(ans, save, nums, it + 1);
        save.pop_back();

        // skip
        solve(ans, save, nums, upper_bound(nums.begin(), nums.end(), *it));
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> save;
        sort(nums.begin(), nums.end());
        solve(ans, save, nums, nums.begin());
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();