class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto beg = t.begin();
        auto end = t.end();
        for (char ch : s) {
            auto found =
                std::find_if(beg, end, [&ch](const char a) { return ch == a; });
            if (found == end)
                return false;
            beg = found + 1;
        }
        return true;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();