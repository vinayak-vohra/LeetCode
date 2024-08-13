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
        solve(arr, ans, temp, k - arr[i], i);

        // not choose
        temp.pop_back();
        solve(arr, ans, temp, k, i + 1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, ans, temp, target);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();