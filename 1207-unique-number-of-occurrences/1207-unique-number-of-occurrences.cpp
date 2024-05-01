class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> count;

        for(int &x: arr)
            count[x]++;

        unordered_set<int> x;
        for(auto &mp: count)
            if(!(x.insert(mp.second).second)) return false;
        
        return true;
    }
};