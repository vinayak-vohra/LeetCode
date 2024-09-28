bool lex_sort(const string& a, const string& b) {
    string::const_iterator sa = a.begin(), sb = b.begin();
    while (sa != a.end() && sb != b.end() && *sa == *sb)
        ++sa, ++sb;

    return sa == a.end() || *sa < *sb;
}

class Solution {
    // TC: O(NLogN)
    // SC: O(N)
    void solve_NLogN(int n, vector<int>& ans) {
        vector<string> nums(n);
        for (int i = 1; i <= n; i++) {
            nums[i - 1] = to_string(i);
        }

        sort(nums.begin(), nums.end(), lex_sort);
        for (string s : nums)
            ans.push_back(stoi(s));
    }

    void solve_N(vector<int>& ans, int n, int base = 0) {
        for (int i = 0; i <= 9 && base <= n - i; i++) {
            // avoid adding 0
            if (!base && !i)
                continue;
            
            ans.push_back(base + i);
            solve_N(ans, n, (base + i) * 10);
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        // solve_NLogN(ans);
        solve_N(ans, n);
        return ans;
    }
};

// 1
// 10 11 12 13 14 15 16 17 18 19
// 2
// 20 21 22 23 24 25
// 3
// 4
// 5
// 6
// 7
// 8
// 9