class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> charCount(26, 0);
        
        for(char &ch : s)
            charCount[ch - 'a']++;

        for(int i = 0; i < s.size(); i++)
            if(charCount[s[i] - 'a'] < 2) 
                return i;
                
        return -1;     
    }
};