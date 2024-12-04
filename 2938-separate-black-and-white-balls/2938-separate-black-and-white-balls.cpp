class Solution {
public:
    long long minimumSteps(string s) {
        auto ans = 0ll;

        // start from first zero from last
        auto endPtr = find(s.rbegin(), s.rend(), '0');

        int zeroCount = 0;

        while (endPtr != s.rend()) {
            if (*endPtr == '0')
                zeroCount++;
            else
                ans += zeroCount;
            ++endPtr;
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