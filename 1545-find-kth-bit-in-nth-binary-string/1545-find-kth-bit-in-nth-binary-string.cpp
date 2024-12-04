class Solution {
public:
    char findKthBit(int n, int k) {
        string ans = "0";

        auto invert = [](char ch) { return ch == '0' ? '1' : '0'; };

        while (--n) {
            string cur = ans;
            transform(begin(cur), end(cur), begin(cur), invert);            
            reverse(begin(cur), end(cur));            

            ans = ans + "1" + cur;            
        }
        
        return ans[k - 1];
    }
};