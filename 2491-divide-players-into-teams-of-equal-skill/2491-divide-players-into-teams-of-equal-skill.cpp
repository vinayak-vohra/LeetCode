class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if (n == 2)
            return skill[0] * skill[1];

        long long sum = 0;
        unordered_map<int, int> freq;

        for (int s : skill) {
            sum += s;
            freq[s]++;
        }

        double target = sum / (n / 2.0);
        // cout << target;

        // cant divide evenly
        if ((target - (int)target) > 0)
            return -1;

        long long ans = 0;

        for (auto s : skill) {
            if (!freq[s])
                continue;

            auto f = freq.find(target - s);
            if (f == freq.end() || f->second == 0)
                return -1;
            ans += (s * f->first);
            freq[s]--;
            f->second--;
        }
        
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();