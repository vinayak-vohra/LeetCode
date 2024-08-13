class Solution {
    void solve(vector<int>& temp, vector<vector<int>>& ans, int k, int n,
               int idx = 1) {
        if (k <= 0 || n <= 0 || idx > 10 - k) {
            if (!k && !n)
                ans.push_back(temp);
            return;
        }

        solve(temp, ans, k, n, idx + 1);
        temp.push_back(idx);
        solve(temp, ans, k - 1, n - idx, idx + 1);
        temp.pop_back();
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(temp, ans, k, n);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();