class Solution {
    int bfs(unordered_map<int, vector<int>>& adj, int target) {
        queue<int> q;
        unordered_set<int> vis;

        q.push(0);
        vis.insert(0);

        int d = 0;

        while (q.size()) {
            int s = q.size();
            d++;
            while (s--) {
                int f = q.front();
                q.pop();
                for (int n : adj[f]) {
                    if (n == target)
                        return d;
                    if (!vis.count(n)) {
                        vis.insert(n);
                        q.push(n);
                    }
                }
            }
        }
        return -1; // wont reach here
    }

public:
    vector<int> shortestDistanceAfterQueries(int n,
                                             vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n - 1; i++) {
            adj[i].push_back(i + 1);
        }

        vector<int> ans;

        for (auto& q : queries) {
            adj[q[0]].push_back(q[1]);
            ans.push_back(bfs(adj, n - 1));
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