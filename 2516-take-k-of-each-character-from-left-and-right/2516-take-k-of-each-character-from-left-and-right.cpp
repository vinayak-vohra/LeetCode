class Solution {
public:
    int takeCharacters(string s, int k) {
        auto less_k = [&k](int a) { return a < k; };
        vector<int> freq(3, 0);
        int n = s.size();
        int ans = n;

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        if (ranges::any_of(freq, less_k))
            return -1;

        int i = n - 1, j = n - 1;

        while (i >= 0) {
            freq[s[i] - 'a']--;

            while (ranges::any_of(freq, less_k)) {
                freq[s[j] - 'a']++;
                j--;
            }
            ans = min(ans, i + n - 1 - j);
            i--;
        }
        return ans;
    }
};