class Solution {
public:
    int maxScore(string s) {
        int score = INT_MIN;
        int cnt_0 = 0, cnt_1 = 0;

        for (int i = 0; i < s.size() - 1; i++)
            cnt_0 += (s[i] == '0'), cnt_1 += (s[i] == '1'),
                score = std::max(score, cnt_0 - cnt_1);
        cnt_1 += (s[s.size() - 1] == '1');
        return score + cnt_1;
    }
};