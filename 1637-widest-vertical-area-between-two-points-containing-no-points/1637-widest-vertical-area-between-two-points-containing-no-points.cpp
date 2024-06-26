class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(),
             [](const auto& a, const auto& b) { return a[0] < b[0]; });

        int maxW = 0;

        for (int i = 1; i < points.size(); ++i) {
            int w = points[i][0] - points[i - 1][0];
            maxW = max(maxW, w);
        }

        return maxW;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();