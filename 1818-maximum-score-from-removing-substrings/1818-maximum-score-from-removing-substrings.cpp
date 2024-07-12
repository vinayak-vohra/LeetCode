#pragma GCC optimize("03", "unroll-loops")

class Solution {
    int gain(string& s, int pt, string sub) {
        string stk;
        int ans = 0;
        for (const char& ch : s) {
            if (!stk.size())
                stk.push_back(ch);
            else if (*stk.rbegin() == sub[0] && ch == sub[1]) {
                stk.pop_back();
                ans += pt;
            } else
                stk.push_back(ch);
        }
        s = stk;
        return ans;
    }

public:
    int maximumGain(string s, int x, int y) {
        return gain(s, x > y ? x : y, x > y ? "ab" : "ba") +
               gain(s, x < y ? x : y, x < y ? "ab" : "ba");
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();