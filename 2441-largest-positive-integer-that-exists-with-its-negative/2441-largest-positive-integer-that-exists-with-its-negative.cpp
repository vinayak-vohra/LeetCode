class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int lt = 0, rt = nums.size() - 1;
        while (lt < rt && nums[lt] < 0) {
            int x = nums[lt] + nums[rt];

            if (!x)
                return nums[rt];
            else if (x < 0)
                lt++;
            else
                rt--;
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