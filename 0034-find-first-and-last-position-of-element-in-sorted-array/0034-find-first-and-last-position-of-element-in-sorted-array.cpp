class Solution {
    int bounds(vector<int>& vect, int s, int e, int t,
               bool (*comp)(const int, const int)) {
        while (s <= e) {
            int m = (s + e) / 2;
            if (comp(t, vect[m]))
                e = m - 1;
            else
                s = m + 1;
        }
        return s;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!nums.size())
            return {-1, -1};

        int lb = bounds(nums, 0, nums.size() - 1, target,
                        [](const int a, const int b) { return a <= b; });

        if (lb == nums.size() || nums[lb] != target)
            return {-1, -1};

        return {lb, bounds(nums, 0, nums.size() - 1, target,
                           [](const int a, const int b) { return a < b; }) -
                        1};
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();