class Solution {
    int solve(string& s, unordered_set<string>& st, int idx = 0) {
        if (idx == s.size())
            return 0;
        int ans = 0;

        for (int i = idx + 1; i <= s.size(); i++) {
            string sub = s.substr(idx, i - idx);
            if (st.find(sub) != st.end())
                continue;

            st.insert(sub);
            ans = max(ans, 1 + solve(s, st, i));
            st.erase(sub);
        }
        return ans;
    }

public:
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return solve(s, st);
    }
};