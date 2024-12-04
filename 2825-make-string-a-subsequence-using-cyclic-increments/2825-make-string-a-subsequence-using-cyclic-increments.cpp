class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int si1 = 0, si2 = 0;
        while (si1 < str1.size() && si2 < str2.size()) {
            if (((str2[si2] - str1[si1]) + 26) % 26 < 2)
                si1++, si2++;
            else
                si1++;
        }
        return si2 == str2.size();
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();