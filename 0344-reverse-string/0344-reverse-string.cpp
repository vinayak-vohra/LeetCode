#pragma GCC optimize("03", "unroll-loops")
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            auto temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }                    
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();