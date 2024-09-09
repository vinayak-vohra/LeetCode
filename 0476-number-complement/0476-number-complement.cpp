class Solution {
public:
    int findComplement(int num) {
        unsigned int t = num;
        unsigned int m = 1;
        while (t) {
            m <<= 1;
            t >>= 1;
        }
        m -= 1;
        return ~num & m;
    }
};