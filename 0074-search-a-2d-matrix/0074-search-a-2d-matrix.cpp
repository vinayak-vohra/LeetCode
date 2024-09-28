class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        int rl = 0, rh = n - 1;
        int row = -1;

        while (rl <= rh) {
            int rm = (rl + rh) / 2;
            if (target < mat[rm][0])
                rh = rm - 1;
            else {
                row = rm;
                rl = rm + 1;
            }
        }

        if (row < 0)
            return 0;
        return binary_search(mat[row].begin(), mat[row].end(), target);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();