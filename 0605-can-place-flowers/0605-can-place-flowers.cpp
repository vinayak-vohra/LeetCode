class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int s = fb.size();
        int i = 0;

        while (i < s && n > 0) {
            if (fb[i]) {
                i += 2;
                continue;
            }

            if ((i == 0 ? 1 : !fb[i - 1]) &&
                (i + 1 == s ? 1 : !fb[i + 1]))
                --n, ++i;

            ++i;
        }

        return n == 0;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();