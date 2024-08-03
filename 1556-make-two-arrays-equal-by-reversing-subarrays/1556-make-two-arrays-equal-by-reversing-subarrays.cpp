#pragma GCC optimize("03", "unroll-loops")
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> freq(1001, 0);

        for (int i = 0; i < arr.size(); ++i) {
            freq[arr[i]]++;
            freq[target[i]]--;
        }

        for (int p : freq)
            if (p)
                return false;
        return true;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();