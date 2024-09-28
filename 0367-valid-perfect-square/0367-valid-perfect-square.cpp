class Solution {

public:
    bool isPerfectSquare(int x) {
        int low = 1, high = x;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid == (double)x / mid)
                return true;
            else if (mid < x / mid) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return false;
    }
};