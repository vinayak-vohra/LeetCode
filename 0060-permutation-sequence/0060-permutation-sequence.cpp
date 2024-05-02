static vector<size_t> fact = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
class Solution {
public:
    string getPermutation(int n, int k) {
        string ans(n, '1');
        iota(ans.begin(), ans.end(), '1');

        int i = 0;

        while (k > 1) {
            int q = (k - 1) / fact[n - i - 1];
            k %= fact[n - i - 1];
            std::rotate(ans.rbegin() + (n - q - 1 - i),
                        ans.rbegin() + (n - q - i), ans.rend() - i);
            i++;
        }
        
        if (!k)
            reverse(ans.begin() + i, ans.end());
        return ans;
    }
};
