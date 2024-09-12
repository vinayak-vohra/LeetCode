#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> freq(allowed.begin(), allowed.end());
        int ans = 0;
        for (string& word : words) {
            bool al = true;
            for (char ch : word)
                if (!freq.count(ch)) {
                    al = false;
                    break;
                }
            ans += al;
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