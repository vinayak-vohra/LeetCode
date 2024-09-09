class Solution {
    // // recursion: TLE
    // bool kSumNSize(int k, int n, vector<int>& ans, int cur = 1) {
    //     if (k < 0 || n < 0 || cur > 6)
    //         return false;
    //     if (k == 0 && n == 0)
    //         return true;

    //     bool done = false;

    //     // pick
    //     ans.push_back(cur);
    //     done = kSumNSize(k - cur, n - 1, ans, cur);

    //     if (!done) {
    //         ans.pop_back();
    //         // skip
    //         done = kSumNSize(k, n, ans, cur + 1);
    //     }

    //     return done;
    // }

public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        long long knownSum = accumulate(rolls.begin(), rolls.end(), 0ll);
        long long unknownSum = mean * (rolls.size() + n) - knownSum;
        vector<int> ans;
        for (int i = n; i > 0; --i) {
            int div = unknownSum / i;
            if (div > 6 || div < 1)
                return {};
            ans.push_back(div);
            unknownSum -= div;
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
