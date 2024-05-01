class Solution {
public:
    string largestGoodInteger(string num)
    {
        int max = -1;
        for (auto it = num.begin(); it < num.end() - 2; it++)
            if (all_of(it, it + 3, [it](const char &c)
                       { return c == *it; }))
                max = std::max(max, (int)*it);

        return max < 0 ? "" : string(3, (char)max);
    }
};