class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for(char ch: s) {
            freq[ch]++;
        }
        bool has_odd = 0;
        int ans = 0;
        for(auto& p: freq) {
            if(p.second & 1) {
                ans += p.second - 1;
                has_odd = 1;
            } else {
                ans += p.second;
            }
        }
        return ans + has_odd;
    }
};