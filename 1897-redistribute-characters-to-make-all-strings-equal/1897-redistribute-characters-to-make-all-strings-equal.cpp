class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> charCount(26, 0);
        int len = words.size();

        for(string &word: words)
        {
            for(char &letter: word)
                charCount[letter - 'a']++;
        }

        return none_of(charCount.begin(), charCount.end(), 
                [&len](int&count){ return count % len; });

    }
};