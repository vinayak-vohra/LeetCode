#pragma GCC optimize("03", "unroll-loops")
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (isdigit(board[i][j])) {
                    char dig = board[i][j];
                    for (int k = 0; k < 9; k++) {
                        int ki = (i / 3) * 3 + k / 3;
                        int kj = (j / 3) * 3 + k % 3;

                        if ((board[i][k] == dig && k != j) ||
                            (board[k][j] == dig && k != i) ||
                            (board[ki][kj] == dig && ki != i && kj != j))
                            return false;
                    }
                }
            }
        }
        return true;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();