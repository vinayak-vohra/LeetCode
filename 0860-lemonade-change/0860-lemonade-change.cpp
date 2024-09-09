class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> cash;
        for (int bill : bills) {
            int x = bill;
            while (bill > 10 && cash[10])
                bill -= 10, cash[10]--;
            while (bill > 5 && cash[5])
                bill -= 5, cash[5]--;
            if (bill != 5)
                return false;
            cash[x]++;
        }
        return true;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();