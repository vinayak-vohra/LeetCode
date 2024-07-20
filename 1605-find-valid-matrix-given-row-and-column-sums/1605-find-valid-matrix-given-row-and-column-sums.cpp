class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                      vector<int>& colSum) {
        int n, m, rp, cp;
        n = rowSum.size();
        m = colSum.size();

        rp = cp = 0;

        vector<vector<int>> ans(n, vector<int>(m, 0));

        while (rp < n && cp < m) {
            int min = std::min(rowSum[rp], colSum[cp]);
            ans[rp][cp] = min;

            rowSum[rp] -= min;
            colSum[cp] -= min;

            if (!rowSum[rp])
                ++rp;
            else
                ++cp;
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