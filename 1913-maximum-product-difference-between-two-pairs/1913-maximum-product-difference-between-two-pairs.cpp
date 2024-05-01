class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1, max2, min1, min2;
        max1 = max2 = INT_MIN;
        min1 = min2 = INT_MAX;

        for (int& n : nums) {
            if (n > max1)
                max2 = max1, max1 = n;
            else if (n > max2)
                max2 = n;

            if (n < min1)
                min2 = min1, min1 = n;
            else if (n < min2)
                min2 = n;
        }

        return max1 * max2 - min1 * min2;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();