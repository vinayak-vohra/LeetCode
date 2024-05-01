class Solution {
public:
    int minSteps(string s, string t)
    {
        vector<int> charCount(26, 0);

        for (int i = 0; i < s.size(); i++)
            charCount[s[i] - 'a']--, charCount[t[i] - 'a']++;

        int ans = 0;
        for (auto &x : charCount)
            ans += (x > 0) ? x : 0;

        return ans;
    }
};