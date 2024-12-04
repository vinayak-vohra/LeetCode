bool isSubFolder(string& a, string& b) {
    // a <= b
    int i = 0, n = a.size();
    for (; i < n; i++) {
        if (a[i] != b[i])
            return false;
    }
    return i == b.size() || b[i] == '/';
}
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        string prev = folder[0];
        vector<string> res = {prev};

        for (string& f : folder) {
            if (!isSubFolder(prev, f)) {
                prev = f;
                res.push_back(f);
            }
        }
        return res;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();