class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        // wptr1, 2 => index of current word in word array
        // lptr1, 2 => index of current letter in current word

        int wptr1 = 0, wptr2 = 0, lptr1 = 0, lptr2 = 0;

        while (wptr1 < word1.size() && wptr2 < word2.size()) {
            if (word1[wptr1][lptr1++] != word2[wptr2][lptr2++])
                return false;

            if (lptr1 == word1[wptr1].size()) {
                lptr1 = 0;
                wptr1++;
            }
            if (lptr2 == word2[wptr2].size()) {
                lptr2 = 0;
                wptr2++;
            }
        }

        return !lptr1 && !lptr2;
    }
};