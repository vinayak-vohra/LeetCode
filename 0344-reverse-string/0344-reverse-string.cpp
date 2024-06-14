class Solution {
public:
    void reverseString(vector<char>& s) {
        int lt = -1, rt = s.size();

        while(++lt < --rt)
            std::swap(s[lt], s[rt]);
        
    }
};