class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        auto last = s.rbegin();
        int count = 0;

        for (char ch : s) {
            if (ch == '[')
                stk.push(ch);
            else if (ch == ']' && stk.size())
                stk.pop();
            else {
                count++;
                last = find(last, s.rend(), '[');
                swap(ch, *last.base());
                ++last;
                stk.push(ch);
            }
        }
        return count;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();