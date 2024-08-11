class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int sum = nums[low] + nums[high];

            if (sum == target)
                return {low + 1, high + 1};

            else if (sum < target)
                low++;
            else
                high--;
        }
        return {};
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();