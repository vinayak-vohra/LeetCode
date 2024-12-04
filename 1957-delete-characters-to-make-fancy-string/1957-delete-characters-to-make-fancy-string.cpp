class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        char prev = '\0';
        bool dup = 0;
        for (char ch : s) {
            if (ch == prev) {
                if (dup)
                    continue;
                else
                    dup = 1;
            } else
                dup = 0;
            prev = ch;
            ans += ch;
        }
        return ans;
    }
};