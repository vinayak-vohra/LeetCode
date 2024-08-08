class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int d = 0;
        int i = 0, j = 0;
        int k = 1, N = n * n;

        while (k <= N) {
            if (i < 0 || j < 0 || i >= n || j >= n || (ans[i][j])) {
                i -= dirs[d].first;
                j -= dirs[d].second;
                d = (d + 1) % 4;
            } else {
                ans[i][j] = k++;
            }
            i += dirs[d].first;
            j += dirs[d].second;
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