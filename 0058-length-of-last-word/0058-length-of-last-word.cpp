class Solution {
public:
    int lengthOfLastWord(string s) {
    // Find end of last word
    auto end_of_last_word = find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                                    { return !isspace(ch); });

    // Find start of last word
    auto start_of_last_word = find_if(end_of_last_word, s.rend(), [](unsigned char ch)
                                      { return isspace(ch); });

    // return length of last word
    return start_of_last_word - end_of_last_word ;
        
    }
};