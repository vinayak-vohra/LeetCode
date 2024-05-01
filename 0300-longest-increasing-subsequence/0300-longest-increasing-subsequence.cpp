class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        ans.push_back(nums[0]);

        for(auto it = nums.begin() + 1; it < nums.end(); it++)
            if(*it > *(ans.end() - 1)) ans.push_back(*it);
            else ans[lower_bound(ans.begin(), ans.end(), *it) - ans.begin()] = *it;

        return ans.size();
    }
};