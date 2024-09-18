class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> x(n);
        for (int i = 0; i < 16; i++) {
            x[i] = x[i] ^ x[31 - i];
            x[31 - i] = x[31 - i] ^ x[i];
            x[i] = x[i] ^ x[31 - i];
        }
        return static_cast<uint32_t>(x.to_ulong());
    }
};