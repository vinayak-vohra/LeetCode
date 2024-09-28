class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        int cnt = freq.begin()->second;
        for (auto& p : freq) {
            if (p.second != cnt)
                return false;
        }
        return true;
    }
};