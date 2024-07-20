class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rMin(n, INT_MAX), cMax(m, INT_MIN), ans;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                rMin[i] = std::min(matrix[i][j], rMin[i]);
                cMax[j] = std::max(matrix[i][j], cMax[j]);
            }
        }

        std::sort(rMin.begin(), rMin.end());
        std::sort(cMax.begin(), cMax.end());

        std::set_intersection(rMin.begin(), rMin.end(), cMax.begin(),
                              cMax.end(), std::back_inserter(ans));

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();