class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        int i = 0;

        string ans = "";
        while (i < n && i < m) {
            ans += word1[i];
            ans += word2[i];
            ++i;
        }

        if (i < n)
            ans += string(word1.begin() + i, word1.end());

        if (i < m)
            ans += string(word2.begin() + i, word2.end());

        return ans;
    }
};