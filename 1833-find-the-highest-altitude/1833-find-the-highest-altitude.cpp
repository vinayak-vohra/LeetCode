class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int x = 0, ans = 0;

        for (int n : gain) {
            x += n;
            ans = std::max(ans, x);
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