class Solution {
public:
    int findMinDifference(vector<string>& tp) {
        vector<int> mins(tp.size());
        transform(tp.begin(), tp.end(), mins.begin(), [](const string& s) {
            return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
        });
        sort(mins.begin(), mins.end());
        int ans = 1e5;
        for (int i = 0; i < tp.size() - 1; i++) {
            ans = min(ans, mins[i + 1] - mins[i]);
        }
        return min(ans, 1440 + mins[0] - mins.back());
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();