class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> mpp(10, 0);

        int min1 = 10;
        for (int n : nums1) {
            if (n < min1)
                min1 = n;
            mpp[n] = 1;
        }

        int min2 = 10;
        int min3 = 10;
        for (int n : nums2) {
            if (mpp[n] && n < min3)
                min3 = n;
            if (n < min2)
                min2 = n;
        }

        if (min3 != 10)
            return min3;

        return min(min1, min2) * 10 + max(min1, min2);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();