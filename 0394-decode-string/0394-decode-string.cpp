class Solution {
public:
    string decodeString(string s) {
        string ans = "";

        for (char ch : s) {
            // start popping letters
            if (ch == ']') {
                string temp = "";

                while (*ans.rbegin() != '[') {
                    temp += *ans.rbegin();
                    ans.pop_back();
                }
                ans.pop_back(); // pop '['

                // start calculating k
                int p = 1, k = 0;
                while (ans.size() && isdigit(*ans.rbegin())) {
                    k += ((*ans.rbegin() - '0') * p);
                    p *= 10;
                    ans.pop_back();
                }
                // reverse temp
                reverse(temp.begin(), temp.end());

                // push resultant back in ans
                while (k--) {
                    ans.append(temp);
                }
            }

            // insert in ans
            else
                ans.push_back(ch);
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();