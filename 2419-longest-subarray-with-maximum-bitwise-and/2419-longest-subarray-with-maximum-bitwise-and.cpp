class Solution {
public:
    int longestSubarray(vector<int>& arr) {
        int ans = 1, maxi = INT_MIN;
        auto it = arr.begin();
        while (it != arr.end()) {
            auto end =
                find_if(it, arr.end(), [&](int ch) { return ch != *it; });

            if (*it > maxi) {
                ans = end - it;
                maxi = *it;
            } else if (*it == maxi)
                ans = max(ans, (int)(end - it));
            it = end;
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