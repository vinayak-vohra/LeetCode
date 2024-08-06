class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, cur = 0;
        for (int n : nums)
            sum += n;

        for (int i = 0; i < nums.size(); ++i) {
            if (cur + nums[i] == sum - cur)
                return i;
            cur += nums[i];
        }
        return -1;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();