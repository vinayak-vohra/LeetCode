class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR = 0;
        for (int n : nums) {
            XOR ^= n;
        }

        int g1_xor = 0;
        int g2_xor = 0;

        int diff = 0;
        while (((XOR >> diff) & 1) != 1) {
            diff++;
        }

        for (int num : nums) {
            if (((num >> diff) & 1) == 1) {
                g1_xor ^= num;
            } else {
                g2_xor ^= num;
            }
        }

        return {g1_xor, g2_xor};
    }
};

auto init = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();