#pragma GCC optimize("03", "unroll-loops")
struct customLess {
    bool operator()(int a, pair<int, int> b) {
        return std::less<int>()(a, b.first);
    }
};

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        int m = profit.size();

        vector<pair<int, int>> zipped(m);
        for (int i = 0; i < m; ++i)
            zipped[i] = {difficulty[i], profit[i]};

        sort(zipped.begin(), zipped.end());

        vector<int> maxUntil(m, zipped[0].second);
        for (int i = 1; i < m; ++i)
            maxUntil[i] = std::max(maxUntil[i - 1], zipped[i].second);

        long ans = 0;
        for (int w : worker) {
            int i = upper_bound(zipped.begin(), zipped.end(), w, customLess()) -
                        zipped.begin();
            ans += i < 1 ? 0 :maxUntil[i - 1];
        }
        return ans;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();