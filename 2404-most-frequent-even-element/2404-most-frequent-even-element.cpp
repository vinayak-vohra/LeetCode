class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq = {{-1, 0}};
        for (int n : nums) {
            if (!(n & 1))
                freq[n]++;
        }
        int ans = -1;
        for (auto& f : freq)
            if (f.second > freq[ans]) {
                ans = f.first;
            } else if (f.second == freq[ans]) {
                ans = min(ans, f.first);
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