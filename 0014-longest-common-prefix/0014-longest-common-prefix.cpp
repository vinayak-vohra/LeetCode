class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string pref = strs[0];
        for (int i = 1; i < strs.size() && pref.size(); i++) {
            int j = 0;
            while (j < pref.size() && strs[i][j] == pref[j] && ++j)
                ;
            pref = pref.substr(0, j);
        }
        return pref;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();