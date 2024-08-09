class Solution {
public:
    bool wordPattern(string p, string s) {
        stringstream ss(s);
        unordered_map<char, string> mp;
        unordered_set<string> mapped;

        int i = 0;
        string w;
        while (ss >> w) {
            char ch = p[i++];
            if (mp.count(ch)) {
                if (mp[ch] != w)
                    return false;
            } else if (mapped.count(w) > 0)
                return false;
            else {
                mp[ch] = w;
                mapped.insert(w);
            }
        }
        return i == p.size();
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();