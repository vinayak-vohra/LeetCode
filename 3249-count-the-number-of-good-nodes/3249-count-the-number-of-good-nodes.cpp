class Solution {
    unordered_map<int, int> size;
    unordered_map<int, bool> vis;

    void dfs(int root, unordered_map<int, vector<int>>& adj, int& count) {
        vis[root] = true;

        vector<int> v = adj[root];

        int curSize = 0;
        unordered_set<int> subtrees;

        for (int node : v) {
            if (!vis[node]) {
                dfs(node, adj, count);
                subtrees.insert(size[node]);
                curSize += size[node];
            }
        }

        if (subtrees.size() <= 1) {
            count++;
        }

        size[root] = curSize + 1;
    }

public:
    int countGoodNodes(vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end());
        unordered_map<int, vector<int>> adj;

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int count = 0;
        dfs(0, adj, count);
        // for (auto& p : size)
        //     cout << p.first << ": " << p.second << '\n';
        return count;
    }
};