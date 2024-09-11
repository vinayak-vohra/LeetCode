class Solution {
public:
    int minimumRecolors(string b, int k) {

        auto beg = b.begin(), end = b.begin() + k;
        int w, ans;
        w = ans = count(beg, end, 'W');

        while (end != b.end()) {
            w -= (*beg == 'W');
            w += (*end == 'W');
            ans = min(ans, w);
            ++beg;
            ++end;
        }
        return min(ans, w);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();