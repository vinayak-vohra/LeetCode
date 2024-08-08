class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int d = 0;

        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int k = n * m;
        int i = 0, j = -1;

        while (ans.size() != k) {
            int ni = i + dirs[d].first;
            int nj = j + dirs[d].second;

            if (ni < 0 || ni >= n || nj < 0 || nj >= m || matrix[ni][nj] > 100)
                d = (d + 1) % 4;
            else {
                i = ni;
                j = nj;
                ans.push_back(matrix[i][j]);
                matrix[i][j] = 101;
            }
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