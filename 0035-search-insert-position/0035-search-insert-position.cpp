class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int beg = 0, end = n - 1;

        while (beg <= end) {
            int mid = (beg + end) / 2;
            if (target <= nums[mid])
                end = mid - 1;
            else
                beg = mid + 1;
        }
        return beg;        
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();