vector<int> keyrow = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3,
                      3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        for (string& word : words) {
            bool valid = true;
            for (int i = 1; i < word.size(); i++) {
                if (keyrow[tolower(word[i]) - 'a'] !=
                    keyrow[tolower(word[i - 1]) - 'a']) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                ans.push_back(word);
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