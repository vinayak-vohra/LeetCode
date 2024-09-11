class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string numstr = to_string(num);
        int l = 0, ans = 0;
        while (l <= numstr.size() - k) {
            int div = stoi(numstr.substr(l++, k));
            if (div)
                ans += (num % div == 0);
        }
        return ans;
    }
};