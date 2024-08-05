class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = *std::max_element(candies.begin(), candies.end());
        int n = candies.size();

        vector<bool> ans(n);

        for (int i = 0; i < n; ++i)
            ans[i] = candies[i] + extraCandies >= maxi;

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();