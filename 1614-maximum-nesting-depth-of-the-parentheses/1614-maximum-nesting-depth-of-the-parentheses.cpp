class Solution {
public:
    int maxDepth(string s) {
        int mxl = 0, l = 0;
        for (char& ch : s) {
            if (ch == '(')
                l++;
            if (ch == ')')
                mxl = std::max(mxl, l--);
        }
        return mxl;
    }
};