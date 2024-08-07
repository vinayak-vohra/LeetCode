class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& one, vector<int>& two) {
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());

        vector<vector<int>> ans(2);

        int skip = -1001;

        int n = one.size(), m = two.size();
        int i = 0, j = 0;

        while (i < n && j < m) {
            if (one[i] < two[j]) {
                if (one[i] != skip) {
                    ans[0].push_back(one[i]);
                    skip = one[i];
                }
                ++i;
            } else if (one[i] > two[j]) {
                if (two[j] != skip) {
                    ans[1].push_back(two[j]);
                    skip = two[j];
                }
                ++j;
            } else {
                skip = one[i];
                ++i;
                ++j;
            }
        }

        while (i < n) {
            if (one[i] != skip) {
                ans[0].push_back(one[i]);
                skip = one[i];
            }
            ++i;
        }
        
        while (j < m) {
            if (two[j] != skip) {
                ans[1].push_back(two[j]);
                skip = two[j];
            }
            ++j;
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