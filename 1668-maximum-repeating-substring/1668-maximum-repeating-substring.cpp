class Solution {
public:
    int maxRepeating(string seq, string word) {
        int ans = 0;
        string w = word;
        while (seq.find(w) != string::npos) {
            ans++;
            w += word;
        }
        return ans;
    }
};