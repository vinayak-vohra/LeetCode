class Solution {
    bool isPalindrome(string& a, int s, int e) {
        while (s < e)
            if (a[s++] != a[e--])
                return false;
        return true;
    }
    bool solve(string& a, string& b) {
        int n = a.size();
        int i = 0;
        while (i < n / 2 && a[i] == b[n - i - 1])
            ++i;
        return (i == n / 2) || isPalindrome(b, i, n - i - 1) ||
               isPalindrome(a, i, n - i - 1);
    }

public:
    bool checkPalindromeFormation(string a, string b) {
        return solve(a, b) || solve(b, a);
    }
};
