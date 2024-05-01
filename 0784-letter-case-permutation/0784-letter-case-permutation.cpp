class Solution {
    void solve(string& s, vector<string>& ans, int i = 0) {
        if (i == s.size()) {
            ans.push_back(s);
            return;
        }

        if (isdigit(s[i]))
            solve(s, ans, i + 1);
        else {
            // don't change
            solve(s, ans, i + 1);

            // change
            char og = s[i];
            s[i] = isupper(og) ? tolower(og) : toupper(og);
            solve(s, ans, i + 1);
            s[i] = og;
        }
    }

public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(s, ans);
        return ans;
    }
};