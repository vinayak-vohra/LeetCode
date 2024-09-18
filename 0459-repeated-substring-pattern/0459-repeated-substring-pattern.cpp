class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string d = s + s;
        d = d.substr(1, d.size() - 2);
        return d.find(s) != string::npos;
    }
};
