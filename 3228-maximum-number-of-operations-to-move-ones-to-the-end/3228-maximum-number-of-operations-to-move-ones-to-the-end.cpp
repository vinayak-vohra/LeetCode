class Solution {
public:
    int maxOperations(string s) {
        int oneCount, i, ans;
        oneCount = ans = i = 0;

        while (i + 1 < s.size()) {
            if (s[i] == '1')
                ++oneCount;

            // condition satisfied
            if (s[i] == '1' && s[i + 1] == '0') {
                // find next one
                while (i < s.size() && s[i] != '1')
                    ++i;

                ans += oneCount;
            }
            ++i;
        }
        return ans;
    }
};