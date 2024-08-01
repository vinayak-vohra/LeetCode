class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;

        for (const string& detail : details)
            if (detail[11] > '6' || (detail[11] == '6' && detail[12] > '0'))
                ++ans;

        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();