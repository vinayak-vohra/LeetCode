#define manhattan(a, b) (abs(a[0] - b[0]) + abs(a[1] - b[1]))
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rc, int cc) {
        vector<vector<int>> ans(rows * cols, vector<int>(2, 0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int idx = i * cols + j;
                ans[idx][0] = i;
                ans[idx][1] = j;
            }
        }
        vector<int> center = {rc, cc};
        sort(ans.begin(), ans.end(),
             [&center](const vector<int>& a, const vector<int>& b) {
                 return manhattan(a, center) < manhattan(b, center);
             });
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();