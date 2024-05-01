// https://leetcode.com/problems/calculate-money-in-leetcode-bank/?envType=daily-question&envId=2023-12-06
// vinayak-vohra
#define sumAp(a, n, d) ((n * (2 * a + (n - 1) * d)) / 2)
class Solution
{
public:
    int totalMoney(int n)
    {
        int weeks = n / 7;
        int leftDays = n % 7;

        return weeks * 28 +
               sumAp(0, weeks, 7) +
               sumAp((1 + weeks), leftDays, 1);
    }
};