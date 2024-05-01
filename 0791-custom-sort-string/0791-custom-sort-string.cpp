class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> count(26, 0);
        for (char& ch : s)
            count[ch - 'a']++;

        string ans = "";
        for (char& ch : order) {
            if (count[ch - 'a'])
                while (count[ch - 'a']--)
                    ans += ch;
        }

        for (int i = 0; i < 26; i++)
            if (count[i] > 0)
                while (count[i]--)
                    ans += ('a' + i);

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();