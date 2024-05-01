class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<long long> cnt(1024, 0);
        cnt[0] = 1;

        int curState = 0;
        long long res = 0;

        for (char c : word) {
            curState ^= 1 << (c - 'a');

            res += cnt[curState];
            for (char odd = 'a'; odd <= 'j'; odd++) {
                int oddState = curState ^ (1 << (odd-'a'));
                res += cnt[oddState];
            }

            cnt[curState]++;
        }

        return res;
    }
};