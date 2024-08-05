class Solution {
    bool isVowel(char ch) {
        switch (ch) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            return true;
        default:
            return false;
        }
    }

public:
    string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (isVowel(s[l]) && isVowel(s[r])) {
                std::swap(s[l++], s[r--]);
            } else if (!isVowel(s[l]))
                ++l;
            else if (!isVowel(s[r]))
                r--;
        }
        return s;
    }
};