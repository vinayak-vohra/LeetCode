class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!i && !j)
                    continue;
                int up = i ? grid[i - 1][j] : INT_MAX;
                int lt = j ? grid[i][j - 1] : INT_MAX;
                grid[i][j] += min(up, lt);
            }
        }
        return grid[n - 1][m - 1];
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();