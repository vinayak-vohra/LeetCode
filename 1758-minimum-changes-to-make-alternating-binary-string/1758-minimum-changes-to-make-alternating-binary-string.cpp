class Solution {
public:
    int minOperations(string s)
    {
        int total_1 = 0, odd_1 = 0;
        int len = s.size();

        
        for (int i = 0; i < len; i++)
            if (s[i] == '1')
                total_1++, odd_1 += (i & 1);
        int common = total_1 - 2 * odd_1;
    
        return min(
            (len / 2 + common),
            (len - len / 2 - common));
    }
};