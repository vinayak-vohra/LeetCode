class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int ans = 0;

        for (int n : nums) {

            // find compliment
            int comp = k - n;

            // domain = N
            if (comp < 1)
                continue;

            // compliment exists
            if (freq[comp] > 0) {
                --freq[comp];
                ++ans;
            } 
            // compliment not found
            // update freq of n for next values
            else {
                freq[n]++;
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