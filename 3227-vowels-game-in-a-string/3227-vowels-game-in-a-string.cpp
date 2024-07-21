class Solution {
public:
    bool doesAliceWin(string s) {
        int vowelCount = 0;
        for(char ch: s)
            vowelCount+=(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
        
        return vowelCount > 0;

    }
};