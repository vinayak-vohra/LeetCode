class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int x: nums) {
            if (x < first) {
                first = x;
            } else if (x < second && x > first) {
                second = x;
            } else if (x > second && x > first)
                return true;
        }
        return false;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();