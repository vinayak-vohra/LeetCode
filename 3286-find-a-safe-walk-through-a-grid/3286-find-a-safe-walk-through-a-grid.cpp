class Solution {
public:
    struct Cell {
        int h;
        int x;
        int y;

        Cell(int h, int i, int j) : h(h), x(i), y(j) {}
        bool operator>(const Cell& that) const { return h > that.h; }
    };

    int dijkstra(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;

        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        pq.push(Cell(grid[0][0], 0, 0));

        vector<vector<int>> health(rows, vector<int>(cols, INT_MAX));
        health[0][0] = grid[0][0];

        while (pq.size()) {
            auto cur = pq.top();
            pq.pop();
            int h = cur.h, x = cur.x, y = cur.y;
            if (x == rows - 1 && y == cols - 1)
                return h;

            for (auto& dir : dirs) {
                int xx = x + dir.first;
                int yy = y + dir.second;

                if (xx >= 0 && xx < rows && yy >= 0 && yy < cols) {
                    int uh = h + grid[xx][yy];

                    if (uh < health[xx][yy]) {
                        health[xx][yy] = uh;
                        pq.push(Cell(uh, xx, yy));
                    }
                }
            }
        }
        return -1;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        return health > dijkstra(grid);
    }
};