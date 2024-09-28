class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        bitset<100> ans;
        for (int n : nums) {
            if (n)
                ans[n - 1] = 1;
        }
        return ans.count();
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();