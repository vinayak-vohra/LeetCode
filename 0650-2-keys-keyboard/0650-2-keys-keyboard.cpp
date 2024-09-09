class Solution {
public:
    int minSteps(int n, int cur = 1, int copy = 0) {
        if (cur > n)
            return INT_MAX;

        if (cur == n)
            return 0;

        // copy
        int x = minSteps(n, cur + cur, cur);
        if (x != INT_MAX)
            return 2 + x;

        // paste
        int y = minSteps(n, cur + copy, copy);
        if (y != INT_MAX)
            return 1 + y;

        return INT_MAX;
    }
};