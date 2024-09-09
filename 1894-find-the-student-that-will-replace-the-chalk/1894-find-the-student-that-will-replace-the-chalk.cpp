class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {

        for (int i = 1; i < chalk.size(); ++i) {
            if (chalk[i - 1] > k)
                return i - 1;
            chalk[i] += chalk[i - 1];
        }

        return (upper_bound(chalk.begin(), chalk.end(), k % chalk.back()) -
                chalk.begin()) %
               chalk.size();
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
