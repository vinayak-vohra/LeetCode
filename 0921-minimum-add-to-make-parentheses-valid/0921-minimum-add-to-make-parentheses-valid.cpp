class Solution {
public:
    int minAddToMakeValid(string s) {
        int unopen = 0, open = 0;

        for (char ch : s) {
            if (ch == '(')
                open++;
            else if (ch == ')' && !open)
                unopen++;
            else
                open--;
        }
        return open + unopen;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();