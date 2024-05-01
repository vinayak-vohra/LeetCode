class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mp(128, -1);
        vector<bool> mk(128, 0);

        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] < 0) {
                if(mk[t[i]])
                    return 0;
                mp[s[i]] = t[i];
                mk[t[i]] = 1;
            }
            else if (mp[s[i]] != t[i])
                return 0;
        }
        return 1;
    }
};