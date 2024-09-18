class Solution {
public:
    bool isCircularSentence(string st) {
        if (st.front() != st.back())
            return false;

        auto it = st.begin();
        while (it != st.end()) {
            it = find_if(it + 1, st.end(), [](char ch) { return isspace(ch); });
            if (it != st.end() && *(it - 1) != *(it + 1))
                return false;
        }
        return true;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();