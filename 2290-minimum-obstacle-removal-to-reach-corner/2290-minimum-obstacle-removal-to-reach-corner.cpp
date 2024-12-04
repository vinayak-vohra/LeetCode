class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int N = m * n;

        vector<int> dist(N, N + 1);
        deque<pair<int, int>> q;

        dist[0] = grid[0][0];
        q.push_back({0, 0});

        vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (q.size()) {
            auto [x, y] = q.front();
            q.pop_front();

            for (auto& d : dirs) {
                int i = x + d.first;
                int j = y + d.second;

                if (i < 0 || i == m)
                    continue;
                if (j < 0 || j == n)
                    continue;

                int from = x * n + y;
                int to = i * n + j;

                if (dist[to] > dist[from] + grid[i][j]) {
                    dist[to] = dist[from] + grid[i][j];

                    if (grid[i][j])
                        q.push_back({i, j});
                    else
                        q.push_front({i, j});
                }
            }
        }

        return dist[N - 1];
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();