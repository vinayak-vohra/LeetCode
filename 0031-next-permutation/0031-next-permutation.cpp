class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // logic: {1, 2, 5, 4, 3}
        // - find 1st unsorted element from end [2]
        // - rverse {1, 2, 3, 4, 5}
        // - find upper bound [3]
        // - swap {1, 3, 2, 4, 5}

        auto sorted = std::is_sorted_until(nums.rbegin(), nums.rend()).base();
        std::reverse(sorted, nums.end());
        if (sorted-- != nums.begin())
            std::swap(*sorted, *std::upper_bound(sorted, nums.end(), *sorted));
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();