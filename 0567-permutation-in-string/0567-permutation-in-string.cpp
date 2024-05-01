#pragma GCC optimize("03","unroll-loops")
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size())
            return false;

        vector<int> freq(26, 0), window(26, 0);

        for (char ch : s1)
            freq[ch - 'a']++;

        int lt = 0, rt = 0;
        for (; rt < s2.size();) {
            window[s2[rt++] - 'a']++;

            if (rt - lt == s1.size()) {
                if (freq == window)
                    return true;
                window[s2[lt++] - 'a']--;
            }
        }
        return false;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();