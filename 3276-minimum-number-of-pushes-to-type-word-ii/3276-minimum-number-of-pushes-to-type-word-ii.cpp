class Solution {
public:
    int minimumPushes(string word) {
        vector<pair<int, int>> freq(26);

        for (int i = 0; i < 26; ++i)
            freq[i] = {0, i};

        for (char ch : word) {
            freq[ch - 'a'].first++;
        }

        sort(freq.begin(), freq.end(), [](pair<int, int> b, pair<int, int> a) {
            return a.first < b.first;
        });

        int ans = 0, i = 0;

        while (i < 26) {
            if (!freq[i].first)
                break;
            ans += (i / 8 + 1) * freq[i].first;
            ++i;
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