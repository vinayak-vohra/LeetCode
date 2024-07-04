class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, long> counter;

        for (int i : nums1)
            counter[i]++;

        vector<int> ans;
        for (int j : nums2) {
            if (counter[j]) {
                ans.push_back(j);
                --counter[j];
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