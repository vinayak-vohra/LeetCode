class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int&n:nums) {
            int i = abs(n);
            if(nums[i] < 0)
                return i;
            nums[i] = -nums[i];
        }
        return -1;
        // while (nums[0] != nums[nums[0]])
        //     swap(nums[0], nums[nums[0]]);
        //  return nums[0];
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();