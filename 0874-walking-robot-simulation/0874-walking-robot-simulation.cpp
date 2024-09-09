class Solution {
    string hasher(int a, int b) { return to_string(a) + "." + to_string(b); }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obSet;
        for (auto& cord : obstacles)
            obSet.insert(hasher(cord[0], cord[1]));

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int cd = 0, x = 0, y = 0, ans = 0;

        for (int com : commands) {
            if (com == -2)
                cd = (cd + 3) % 4;
            else if (com == -1)
                cd = (cd + 1) % 4;
            else {
                while (com--) {
                    int dx = x + dirs[cd].first;
                    int dy = y + dirs[cd].second;
                    if (obSet.count(hasher(dx, dy)))
                        break;
                    x = dx;
                    y = dy;
                    ans = max(ans, x * x + y * y);
                }
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