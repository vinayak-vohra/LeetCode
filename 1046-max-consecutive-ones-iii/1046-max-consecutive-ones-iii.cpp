class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l, r, ans, zero;
        l = r = ans = zero = 0;

        while (r < nums.size()) {
            if (nums[r] || zero < k) {
                zero += !nums[r];
                ans = std::max(ans, r - l + 1);
            }

            else {
                while (nums[l]) {
                    zero -= !nums[l];
                    ++l;
                }
                ++l;
            }
            ++r;
        }
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();