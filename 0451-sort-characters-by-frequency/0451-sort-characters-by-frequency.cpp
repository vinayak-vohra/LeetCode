class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> chCount;
        for(char& ch: s)
            chCount[ch]++;

        vector<pair<int, char>> vect;
        for(auto& p: chCount)
            vect.push_back({p.second, p.first});

        sort(vect.begin(), vect.end());

        string res;
        for(auto it = vect.rbegin(); it!= vect.rend(); it++)
            res.append(string(it->first, it->second));

        return res;
    }
};