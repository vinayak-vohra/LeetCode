class Solution {
    int setbits(int num) { return __builtin_popcount(num); }

public:
    bool canSortArray(vector<int>& nums) {
        int prev = INT_MIN;
        int i = 0, j = 1, n = nums.size();

        while (i < n) {
            int b = setbits(nums[i]);

            while (j < n && setbits(nums[j]) == b)
                j++;

            sort(nums.begin() + i, nums.begin() + j);

            if (prev > nums[i])
                return false;

            prev = nums[j - 1];

            i = j;
        }

        return true;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();