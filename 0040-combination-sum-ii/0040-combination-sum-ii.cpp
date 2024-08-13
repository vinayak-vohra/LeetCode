class Solution {
    void solve(vector<int>& arr, vector<vector<int>>& ans, vector<int>& temp,
               int k, int i = 0) {
        if (i == arr.size() || k <= 0) {
            if (!k)
                ans.push_back(temp);
            return;
        }

        // choose
        temp.push_back(arr[i]);
        solve(arr, ans, temp, k - arr[i], i + 1);
        temp.pop_back();

        // not choose
        solve(arr, ans, temp, k,
              upper_bound(arr.begin() + i, arr.end(), arr[i]) - arr.begin());
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(c.begin(), c.end());
        solve(c, ans, temp, target);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();