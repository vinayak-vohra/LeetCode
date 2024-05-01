class Solution {
public:
    int minimumLength(string s) {
        int beg = 0;
        int end = s.size() - 1;

        while (beg < end) {
            if (s[beg] != s[end])
                break;

            char ch = s[beg];
            while (beg <= end) {
                if (s[beg] == ch)
                    beg++;
                else if (s[end] == ch)
                    end--;
                else
                    break;
            }
        }
        return end - beg + 1;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();