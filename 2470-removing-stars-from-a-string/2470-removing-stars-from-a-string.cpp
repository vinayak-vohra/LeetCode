class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        for (char ch : s) {
            if (ch == '*')
                ans.pop_back();
            else
                ans.push_back(ch);
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();