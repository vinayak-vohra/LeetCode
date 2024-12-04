class Solution {
public:
    bool rotateString(string s, string goal) {
        s += s;
        return s.size() == 2 * goal.size() && s.find(goal) != string::npos;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();