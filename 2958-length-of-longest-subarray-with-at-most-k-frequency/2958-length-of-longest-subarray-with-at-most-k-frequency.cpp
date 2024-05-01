class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, queue<int>> mp;
        int l, r, maxLen;
        l = r = maxLen = 0;
        while (r < nums.size()) {
            if (mp[nums[r]].size() == k) {
                int i = mp[nums[r]].front();
                while (l <= i) {
                    mp[nums[l++]].pop();
                }
            }
            mp[nums[r]].push(r++);
            maxLen = std::max(maxLen, r - l);
        }
        return maxLen;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();