class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for (int i = 1; i < arr.size(); i++)
            arr[i] ^= arr[i - 1];

        vector<int> ans;
        for (auto& query : queries) {
            if (!query[0])
                ans.push_back(arr[query[1]]);
            else
                ans.push_back(arr[query[1]] ^ arr[query[0] - 1]);
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