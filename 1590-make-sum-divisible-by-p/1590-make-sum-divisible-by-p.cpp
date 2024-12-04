class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = accumulate(nums.begin(), nums.end(), 0ll);

        // remainder needed to be removed
        int extra = total % p;

        // already divisible
        if (!extra)
            return 0;

        int n = nums.size();

        unordered_map<int, int> pmap; // to keep track of sum and index
        int sum = 0, mini = n;        // maximum elements that can be removed
        pmap[0] = -1;

        for (int i = 0; i < n; i++) {
            sum = (sum + nums[i]) % p;
            int rem = (sum - extra + p) % p;

            if (pmap.count(rem)) {
                mini = min(mini, i - pmap[rem]);
            }
            pmap[sum] = i;
        }
        return mini == n ? -1 : mini;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();