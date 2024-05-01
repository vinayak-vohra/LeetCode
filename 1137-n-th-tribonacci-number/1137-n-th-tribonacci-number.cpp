class Solution {
public:
    int tribonacci(int n) {
        if (n == 0)
            return 0;
        else if (n == 1 || n == 2)
            return 1;
        int first = 0, second = 1, third = 1;
        int ans;
        for (int i = 3; i <= n; i++) {
            ans = first + second + third;
            first = second;
            second = third;
            third = ans;
        }
        return ans;
    }
};