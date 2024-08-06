constexpr bool isVowel(const char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}
class Solution {
public:
    int maxVowels(string s, int k) {
        if (k == 1)
            return std::find_if(s.begin(), s.end(), isVowel) != s.end();

        int l, r, cur, ans;
        l = 0, r = k;
        ans = cur = std::count_if(s.begin(), s.begin() + k, isVowel);

        while (r < s.size()) {
            cur += isVowel(s[r++]);
            cur -= isVowel(s[l++]);
            ans = std::max(cur, ans);
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