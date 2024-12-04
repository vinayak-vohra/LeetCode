class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int mb) {
        int st = 0;
        int maxi = (1 << mb) - 1;

        for (int& x : nums) {
            st ^= x;
            x = st ^ maxi;
        }

        reverse(nums.begin(), nums.end());

        return nums;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();