class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n ||n==INT_MIN)
        return 0;
        return !(n&(n-1));
    }
};