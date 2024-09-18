class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        for (auto& row : grid)
            sort(row.begin(), row.end());

        int ans = 0;
        for (int j = grid[0].size() - 1; j >= 0; j--) {
            int maxi = INT_MIN;
            for (int i = 0; i < grid.size(); i++) {
                maxi = max(maxi, grid[i][j]);
            }
            ans += maxi;
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