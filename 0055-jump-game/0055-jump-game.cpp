class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int j = n - 1;
        for (int i = j - 1; i >= 0; i--) {
            if (i + nums[i] >= j)
                j = i;
        }
        return !j;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();