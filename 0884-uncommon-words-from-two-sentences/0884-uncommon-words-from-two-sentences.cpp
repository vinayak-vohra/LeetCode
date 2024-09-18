class Solution {
    void solve(string& s, unordered_map<string, int>& wc) {
        auto it = s.begin();
        auto end = it;
        while (end != s.end()) {
            end =
                find_if(it, s.end(), [](const char ch) { return isspace(ch); });

            wc[string(it, end)]++;
            it = end + 1;
        }
    }

public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wc;
        solve(s1, wc);
        solve(s2, wc);

        vector<string> ans;
        for (auto& p : wc) {
            if (p.second == 1)
                ans.push_back(p.first);
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