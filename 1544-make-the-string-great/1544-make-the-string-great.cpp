class Solution {
public:
    string makeGood(string s) {
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (res.size() && ((*res.rbegin() & 31) == (s[i] & 31)) &&
                *res.rbegin() != s[i])
                res.pop_back();
            else
                res.push_back(s[i]);
        }
        return res;
    }
};