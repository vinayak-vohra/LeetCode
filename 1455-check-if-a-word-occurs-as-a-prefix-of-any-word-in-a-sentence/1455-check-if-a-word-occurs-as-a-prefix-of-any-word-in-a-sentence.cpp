class Solution {
public:
    int isPrefixOfWord(string s, string w) {
        int i = 0;
        while (1) {
            i = s.find(w, i);
            if (i == string::npos || i == 0 || s[i - 1] == ' ')
                break;
            i++;
        }

        if (i == string::npos)
            return -1;

        return count(s.begin(), s.begin() + i, ' ') + 1;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();