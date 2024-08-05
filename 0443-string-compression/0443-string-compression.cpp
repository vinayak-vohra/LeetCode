class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        int c = 1;
        for (int i = 0; i < chars.size() - 1; ++i) {
            if (chars[i] == chars[i + 1])
                ++c;
            else {
                s += chars[i];
                if (c > 1)
                    s += to_string(c);
                c = 1;
            }
        }
        s += chars.back();
        if (c > 1)
            s += to_string(c);

        chars = vector<char>(s.begin(), s.end());
        return s.size();
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();