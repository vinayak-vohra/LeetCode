class Solution {
public:
    long long maximumHappinessSum(vector<int>& hp, int k) {
        sort(hp.begin(), hp.end(), std::greater<int>());
        // sort(hp.rbegin(), hp.rend());
        int i = 0;
        long long ans = 0;
        while (k-- && hp[i] > i)
            ans += hp[i] - (i++);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();