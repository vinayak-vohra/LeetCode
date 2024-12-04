class Solution {
    bool canDistribute(int n, vector<int>& qts, int k) {
        for (int q : qts) {
            n -= ceil((double)q / k);
            if (n < 0)
                return false;
        }
        return true;
    }

public:
    int minimizedMaximum(int n, vector<int>& qts) {
        int low = 1, high = *max_element(qts.begin(), qts.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool ok = canDistribute(n, qts, mid);
            // cout << mid << ' ' << (ok ? "true" : "false") << '\n';
            if (ok) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
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