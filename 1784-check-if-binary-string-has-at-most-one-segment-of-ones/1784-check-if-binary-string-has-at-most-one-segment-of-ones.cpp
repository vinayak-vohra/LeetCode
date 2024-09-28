class Solution {
public:
    bool checkOnesSegment(string s) {
        auto first = find(s.begin(), s.end(), '1');
        auto last = find(s.rbegin(), s.rend(), '1');
        auto zero = find(first, last.base(), '0');
        
        return (zero == last.base());
    }
};