class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        size_t lasers = 0;
        int prev_devices = 0, ones;

        for (string& floor : bank) {
            ones = 0;
            for (char& ch : floor)
                if (ch == '1')
                    ones++;

            if (!ones)
                continue;

            if (prev_devices && ones)
                lasers += (prev_devices * ones);

            prev_devices = ones;
        }
        return lasers;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();