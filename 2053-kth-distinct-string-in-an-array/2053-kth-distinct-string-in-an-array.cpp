class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> unq;

        for (string& s : arr) {
            unq[s]++;
        }

        for (string& s : arr) {
            if (unq[s] == 1 && !--k)
                return s;
        }
        return "";
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

