class Solution {
    void solve(vector<string>& board, vector<vector<string>>& ans,
               vector<vector<bool>>& mark, int curCol = 0) {
        int n = board.size();
        if (curCol == n) {
            ans.push_back(board);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!mark[0][(n - 1) + (curCol - i)] && !mark[1][i] &&
                !mark[2][curCol + i]) {
                board[i][curCol] = 'Q';
                mark[0][(n - 1) + (curCol - i)] = mark[1][i] =
                    mark[2][curCol + i] = 1;

                solve(board, ans, mark, curCol + 1);

                board[i][curCol] = '.';
                mark[0][(n - 1) + (curCol - i)] = mark[1][i] =
                    mark[2][curCol + i] = 0;
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<vector<bool>> mark(3, vector<bool>(2 * n - 1, 0));

        solve(board, ans, mark);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();