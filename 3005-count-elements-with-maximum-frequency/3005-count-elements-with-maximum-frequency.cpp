#pragma GCC optimize("03", "unroll-loops")
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> fr(101, 0);
        int max = 0, cnt = 0;
        for (int& n : nums) {
            fr[n]++;
            cnt += (fr[n] == max);
            if (fr[n] > max)
                cnt = 1, max = fr[n];
        }
        return max * cnt;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();