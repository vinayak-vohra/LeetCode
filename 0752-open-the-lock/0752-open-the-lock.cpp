#pragma GCC optimize("03", "unroll-loops")
class Solution {
public:
    int openLock(vector<string>& de, string target) {
        string src = "0000";
        unordered_set<string> vis(de.begin(), de.end());

        if (vis.count(src))
            return -1;

        vis.insert(src);

        queue<string> q;
        q.push(src);
        int ans = 0;

        while (q.size()) {
            int n = q.size();
            while (n--) {
                auto f = q.front();
                q.pop();
                if (f == target)
                    return ans;
                for (int i = 0; i < 4; i++) {
                    int og = f[i] - '0';
                    f[i] = '0' + ((og + 1) % 10);
                    if (f == target)
                        return ans + 1;
                    if (!vis.count(f)) {
                        vis.insert(f);
                        q.push(f);
                    }

                    f[i] = '0' + ((og + 9) % 10);
                    if (f == target)
                        return ans + 1;
                    if (!vis.count(f)) {
                        vis.insert(f);
                        q.push(f);
                    }
                    f[i] = og + '0';
                }
            }
            ans++;
        }
        return -1;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();