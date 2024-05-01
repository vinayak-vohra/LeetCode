class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> won;
        unordered_map<int, int> lost;
        vector<vector<int>> res(2, vector<int>());

        for (auto& match : matches) {
            won[match[0]]++;
            lost[match[1]]++;
        }

        for (auto& x : won) {
            if (lost.find(x.first) == lost.end())
                res[0].push_back(x.first);
        }

        for (auto& x : lost) {
            if (x.second == 1)
                res[1].push_back(x.first);
        }
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());

        return res;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();