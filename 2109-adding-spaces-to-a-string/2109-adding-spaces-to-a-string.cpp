class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        // ranges::sort(spaces);
        int vi = 0, si = 0;
        string res = "";

        // while (vi < spaces.size()) {
        //     if (si == spaces[vi])
        //         res += ' ', vi++;
        //     else
        //         res += s[si], si++;
        // }
        // copy(s.begin() + si, s.end(), std::back_inserter(res));

        while (si < s.size()) {
            if (vi < spaces.size() && si == spaces[vi]) {
                res += ' ';
                vi++;
            } else {
                res += s[si];
                si++;
            }
        }

        return res;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();