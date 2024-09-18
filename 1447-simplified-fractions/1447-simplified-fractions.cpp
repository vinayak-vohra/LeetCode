class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        if (n == 1)
            return ans;

        for (int i = 1; i < n; i++) {
            string num = to_string(i) + "/";
            for (int j = i + 1; j <= n; j++) {
                if (__gcd(i, j) == 1) {
                    ans.push_back(num + to_string(j));
                }
            }
        }
        return ans;
    }
};