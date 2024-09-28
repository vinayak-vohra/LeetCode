class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            if (n % (i + 1) == 0)
                ans += (nums[i] * nums[i]);

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();