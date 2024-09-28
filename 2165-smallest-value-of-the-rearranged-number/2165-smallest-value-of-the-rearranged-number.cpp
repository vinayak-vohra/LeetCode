class Solution {
public:
    long long smallestNumber(long long num) {
        string numstr = to_string(num);
        sort(numstr.begin(), numstr.end());

        if (num < 0) {
            reverse(numstr.begin(), numstr.end());
            return -(stoll(numstr));
        } else {
            auto it = find_if(numstr.begin(), numstr.end(),
                              [](const char ch) { return ch != '0'; });
            if (it != numstr.end())
                swap(*it, *numstr.begin());
            return stoll(numstr);
        }
    }
};

