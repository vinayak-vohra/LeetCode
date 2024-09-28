class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == nums[mid - 1]) {
                if (mid & 1)
                    low = mid + 1;
                else
                    high = mid;
            } else if (nums[mid] == nums[mid + 1]) {
                if (mid & 1)
                    high = mid - 1;
                else
                    low = mid + 1;
            } else
                return nums[mid];
        }
        return nums[low];
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
