class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& og, int m, int n) {
        if (og.size() != m * n)
            return {};

        // vector<vector<int>> ans(m);

        // for (int i = 0; i < m; ++i) {
        //     ans[i] =
        //         vector<int>(og.begin() + (n * i), og.begin() + (n * (i +
        //         1)));
        // }

        vector<vector<int>> ans;
        int k = 0;
        for (int i = 0; i < m; ++i) {
            ans.push_back({});
            for (int j = 0; j < n; ++j)
                ans[i].push_back(og[k++]);
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