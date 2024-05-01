class Solution {
    struct Neg{
        int index = -1;
    };

public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, Neg> indexMapper;
        unordered_map<char, Neg> lastIndex;

        for(int i = 0; i < s.size(); i++)
        {
            if(indexMapper[s[i]].index != -1)
                lastIndex[s[i]].index = i;
            
            else 
                indexMapper[s[i]].index = i;
        }
        int maxx = -1;
        for(auto &last: lastIndex)
            maxx = max(maxx, last.second.index - indexMapper[last.first].index - 1);
        return maxx;
    }
};