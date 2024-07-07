class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = 0, ans = 0;

        while(numBottles) {
            ans += numBottles;
            empty += numBottles;
            numBottles = empty / numExchange;
            empty %= numExchange;
        }

        return ans;

        /*
        if (numBottles < numExchange)
            return numBottles;

        int ans = 0;
        int filled = numBottles, empty = 0;
        do {
            ans += filled;
            empty += filled;
            int replacable = empty / numExchange;
            filled = replacable;
            empty %= numExchange;
        } while (filled);
        */
    }
};