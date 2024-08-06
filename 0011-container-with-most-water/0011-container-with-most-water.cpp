class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans = -1;
        int l = 0, r = h.size() - 1;

        while (l < r) {
            int mini = std::min(h[l], h[r]);
            ans = std::max(ans,  mini * (r - l));

            if (h[l] == mini)
                ++l;
            else
                --r;
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