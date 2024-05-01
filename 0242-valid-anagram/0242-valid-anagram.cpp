class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() !=  t.size()) 
            return false;
        
        vector<int> alphas(26, 0);

        for(int i = 0; i < s.size(); i++)
            alphas[s[i] - 'a']++, alphas[t[i] - 'a']--;

        for(auto &alpha: alphas)
            if(alpha) 
                return false;

        return true;
    }
};