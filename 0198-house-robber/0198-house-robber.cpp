class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();

        if(size == 1) 
            return nums[0];

        for(int i = 2; i < size; i++)
        {
            if(i == 2)
                nums[i] += nums[0];

            else 
                nums[i] += std::max(nums[i - 2], nums[i - 3]);
        }
        
        return std::max(nums[size - 1], nums[size - 2]);
    }
};