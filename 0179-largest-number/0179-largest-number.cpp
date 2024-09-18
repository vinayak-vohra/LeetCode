class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numStr(nums.size());

        // convert to string array
        transform(nums.begin(), nums.end(), numStr.begin(),
                  [](const int n) { return to_string(n); });

        // custom sort
        sort(
            numStr.begin(), numStr.end(),
            [](const string& a, const string& b) { return (a + b) > (b + a); });

        // all zeroes
        if (numStr[0] == "0")
            return "0";

        string ans = "";

        // concat & return
        return accumulate(numStr.begin(), numStr.end(), ans);
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();