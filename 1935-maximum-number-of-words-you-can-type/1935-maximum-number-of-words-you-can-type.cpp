class Solution {
public:
    int canBeTypedWords(string text, string broken) {
        bool canType = true;
        int ans = 0;
        sort(broken.begin(), broken.end());
        for (char ch : text) {
            if (ch == ' ') {
                ans += canType;
                canType = 1;
            } else if (!canType) {
                continue;
            } else {
                canType = !(binary_search(broken.begin(), broken.end(), ch));
            }
        }
        return ans + canType;
    }
};

