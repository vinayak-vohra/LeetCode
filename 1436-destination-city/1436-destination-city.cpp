class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, bool> hasPath;

        for (vector<string>& path : paths)
            hasPath[paths[0]] = 1, hasPath[paths[1]] |= 0;

        for (auto &mp : hasPath)
            if (!mp.second)
                return mp.first;

        return "";
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();