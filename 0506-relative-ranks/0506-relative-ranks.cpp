#pragma GCC optimize("03", "unroll-loops")
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> index(n);

        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(),
             [&score](const int a, const int b) { return score[b] < score[a]; });

        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            if (i == 0)
                ans[index[i]] = "Gold Medal";
            else if(i==1)
                ans[index[i]] = "Silver Medal";
            else if(i==2)
                ans[index[i]] = "Bronze Medal";
            else
            ans[index[i]] = to_string(i+1);
        }

        return ans;
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();