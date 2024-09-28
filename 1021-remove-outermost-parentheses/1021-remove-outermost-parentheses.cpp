class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int open_in_ans = 0;
        stack<char> stk;

        for (char ch : s) {
            if (stk.empty()) {
                stk.push(ch);
            } else if (ch == '(') {
                ans += ch;
                open_in_ans++;
            } else if (ch == ')' && open_in_ans) {
                ans += ch;
                open_in_ans--;
            } else {
                stk.pop();
            }
        }

        return ans;
    }
};