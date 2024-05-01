class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        auto it = word.begin();

        for (; it != word.end(); ++it)
            if (*it == ch)
                break;

        if (it != word.end())
            reverse(word.begin(), it + 1);
        return word;
    }
};