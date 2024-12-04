class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> dec;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (dec.empty() || nums[dec.top()] > nums[i])
                dec.push(i);
        }

        int ans = 0;
        for (int j = n - 1; j >= 0; --j) {
            while (dec.size() && nums[dec.top()] <= nums[j]) {
                ans = max(ans, j - dec.top());
                dec.pop();
            }
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