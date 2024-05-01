class Solution {
    void next_permutation(vector<int>& nums) {
        auto sorted = std::is_sorted_until(nums.rbegin(), nums.rend()).base();
        std::reverse(sorted, nums.end());
        if (sorted-- != nums.begin())
            std::swap(*sorted, *std::upper_bound(sorted, nums.end(), *sorted));
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp(nums.begin(), nums.end());

        do {
            next_permutation(nums);
            ans.push_back(nums);
        } while (temp != nums);

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();