class Solution {
public:
    void reverseString(vector<char>& s) {
        int lt = -1, rt = s.size();

        while(++lt < --rt) {
            auto temp = s[lt];
            s[lt] = s[rt];
            s[rt] = temp;
        }                    
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();