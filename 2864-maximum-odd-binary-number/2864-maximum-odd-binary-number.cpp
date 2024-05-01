class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(s.begin(), s.end());
        auto lb = lower_bound(s.begin(), s.end(), '1');
        swap(*s.begin(), *lb);
        reverse(s.begin(), s.end());
        return s;
    }
};