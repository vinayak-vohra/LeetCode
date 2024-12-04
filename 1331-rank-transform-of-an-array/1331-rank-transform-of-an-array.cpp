class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (!n)
            return {};
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        vector<int> ans(n);
        ans[0] = 1;
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + (temp[i] != temp[i - 1]);
        }
        for (int& a : arr) {
            a = ans[(lower_bound(temp.begin(), temp.end(), a) - temp.begin())];
        }
        return arr;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();