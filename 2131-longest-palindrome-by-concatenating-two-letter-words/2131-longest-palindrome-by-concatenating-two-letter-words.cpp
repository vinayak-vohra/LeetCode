constexpr string getR(string s) {
    std::swap(s[0], s[1]);
    return s;
}

constexpr bool isP(string s) { return s[0] == s[1]; }

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        int ans = 0;
        for (string& s : words) {
            string r = getR(s);

            if (freq[r] > 0) {
                freq[r]--;
                ans += 4;
            } else if (s == r && freq[s] > 1) {
                ans += 4;
                freq[s] -= 2;
            } else
                freq[s]++;
        }
        for (auto& p : freq)
            if (isP(p.first) && p.second) {
                ans += 2;
                break;
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