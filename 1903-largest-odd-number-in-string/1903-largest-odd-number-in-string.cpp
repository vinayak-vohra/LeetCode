class Solution {
public:
    string largestOddNumber(string &num) {
        return string(num.begin(), find_if(num.rbegin(), num.rend(), [](const char &c)
                                    { return c % 2; })
                                .base());
    }
};