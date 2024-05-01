class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for(int& num: nums)
            count[num]++;

        for(auto p: count)
            if(p.second > nums.size() / 2)
                return p.first;
        return -1;
    }
};