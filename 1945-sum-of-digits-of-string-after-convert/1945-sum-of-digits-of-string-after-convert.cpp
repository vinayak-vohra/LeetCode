int addDigits(int num) {
    int sum = 0;
    while (num) {
        sum += (num % 10);
        num /= 10;
    }
    return sum;
}
class Solution {

public:
    int getLucky(string s, int k) {
        int sum = 0;
        for (char ch : s) {
            sum += addDigits(ch - 'a' + 1);
        }

        while (--k && sum > 9) {
            sum = addDigits(sum);
        }
        return sum;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();