class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> prev = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= prev[1])
                prev[1] = max(intervals[i][1], prev[1]);
            else {
                ans.push_back(prev);
                prev = intervals[i];
            }
        }
        ans.push_back(prev);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();