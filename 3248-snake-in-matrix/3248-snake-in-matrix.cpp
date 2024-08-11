class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        unordered_map<string, pair<int, int>> dir = {{"UP", {-1, 0}},
                                                     {"RIGHT", {0, 1}},
                                                     {"DOWN", {1, 0}},
                                                     {"LEFT", {0, -1}}};
        int i = 0, j = 0;
        for (string& s : commands) {
            i += dir[s].first;
            j += dir[s].second;
        }
        return (i * n + j);
    }
};