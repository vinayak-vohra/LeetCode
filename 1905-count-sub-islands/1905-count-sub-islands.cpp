class Solution {
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool isSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2,
                     int r, int c) {
        if (r < 0 || c < 0 || r >= grid1.size() || c >= grid1[0].size() ||
            !grid2[r][c])
            return 1;
        bool ans = 1;
        if (!grid1[r][c])
            ans = 0;
        grid2[r][c] = 0;
        for (auto& dir : dirs)
            ans &= isSubIsland(grid1, grid2, r + dir.first, c + dir.second);
        return ans;
    }

public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        int r = grid1.size();
        int c = grid1[0].size();
        int ans = 0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (grid2[i][j])
                    ans += isSubIsland(grid1, grid2, i, j);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();